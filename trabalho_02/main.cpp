#include "include/Camera.h"
#include "include/Sphere.h"
#include "include/Vec3.h"
#include "include/Light.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cmath>

Vec3 pixelColor(Sphere& s, Light& light, Vec3& dir, Vec3 point) {
    Vec3 v = (dir * -1.0).norm();
    Vec3 l = (light.getPosition() - point).norm();
    Vec3 n = s.getNormal(point);
    Vec3 r = n * (2.0 * (l.dot(n))) - l;
    double nl = n.dot(l);
    double rv = r.dot(v);
    Vec3 e_dif = (nl > 0.0) ? light.getIntensity().cross_at(s.getKDif()) * nl : Vec3 {0, 0, 0};
    Vec3 e_esp = (rv > 0.0) ? light.getIntensity().cross_at(s.getKEsp()) * pow(rv, s.getAlpha()) : Vec3 {0, 0, 0};
    return e_dif + e_esp;
}

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    Camera eye(Vec3 {0, 0, 0});
    double distance_window = 1.0;
    double aspect_ratio = 16.0 / 9.0;
    int window_width = 1000;
    int window_height = int(window_width / aspect_ratio);
    window_height = (window_height < 1) ? 1 : window_height;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(window_width)/window_height);
    Vec3 viewport_horizontal(viewport_width, 0, 0);
    Vec3 viewport_vertical(0, -viewport_height, 0);
    Vec3 pixel_delta_horizontal = viewport_horizontal / window_width;
    Vec3 pixel_delta_vertical = viewport_vertical / window_height;
    Vec3 viewport_upper_left = eye.getPoint()
        - Vec3(0, 0, distance_window) - viewport_horizontal / 2 - viewport_vertical / 2;
    Vec3 pixel00_loc = viewport_upper_left + (pixel_delta_horizontal + pixel_delta_vertical) * 0.5;

    bool isRunning = true;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }
    if (!SDL_CreateWindowAndRenderer("Teste", window_width, window_height, 0, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    // Elements of the scene
    Sphere s(0.5, Vec3 {0.0, 0.0, -1.0}, Vec3 {1.0, 0.0, 0.0}, Vec3 {0.5, 0.5, 0.5}, 5.0);
    Camera cam(Vec3 {0.0, 0.0, 0.0});
    Light light(Vec3 {0, 5, 0}, Vec3 {0.7, 0.7, 0.7});

    // Main loop
    while (isRunning) {
        // Exit
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }

        // Iterate through the window
        for (int l = 0; l < window_height; ++l) {
            for (int c = 0; c < window_width; ++c) {
                Vec3 pixel_center = pixel00_loc + (pixel_delta_horizontal * c) + (pixel_delta_vertical * l);
                Vec3 ray_direction = pixel_center - eye.getPoint();
                Ray r(eye.getPoint(), ray_direction.norm());
                double t = s.intercepts(r);
                if (t >= 0.0) {
                    Vec3 color = pixelColor(s, light, ray_direction, r.at(t));
                    SDL_SetRenderDrawColor(renderer, int(color.x * 255.999), int(color.y * 255.999), int(color.z * 255.999), SDL_ALPHA_OPAQUE); // Sphere color
                    SDL_RenderPoint(renderer, c, l);
                } else {
                    SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
                    SDL_RenderPoint(renderer, c, l);
                }
            }
        }
        SDL_RenderPresent(renderer);
    }

    // Exit gracefully
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
