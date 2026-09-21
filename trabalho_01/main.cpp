#include "include/Camera.h"
#include "include/Sphere.h"
#include "include/Vec3.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

int main(int argc, char* argv[]) {
    // SDL variables
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    // Window specific variables
    // Using image partitions the size of a pixel
    const double distance_window = 10.0;
    const int width = 400;
    const int height = 400;
    const double radius_sphere = 300.0;
    bool isRunning = true;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }
    if (!SDL_CreateWindowAndRenderer("Teste", width, height, 0, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    // Elements of the scene
    Sphere s(radius_sphere, Vec3 {0.0, 0.0, -(distance_window + radius_sphere) + 4.0});
    Camera cam(Vec3 {0.0, 0.0, 0.0});

    // Main loop
    while (isRunning) {
        // Exit
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE); // Background
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE); // Sphere color

        // Iterate through the window
        for (int l = 0; l < height; ++l) {
            double y = height / 2.0 - l;
            for (int c = 0; c < width; ++c) {
                double x = -width / 2.0 + c;
                Ray r(cam.getPoint(), Vec3 {x, y, -distance_window});
                if (s.intercepts(r))
                    SDL_RenderPoint(renderer, x + width / 2.0, -y + height / 2.0);
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
