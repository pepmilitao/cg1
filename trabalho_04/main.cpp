#include "include/Camera.h"
#include "include/Cilinder.h"
#include "include/Color.h"
#include "include/Cone.h"
#include "include/Scene.h"
#include "include/Sphere.h"
#include "include/Plane.h"
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
#include <memory>

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    Camera eye(Vec3 {0, 0, 0});
    Scene scene(&window, &renderer, 1.0, 500, 0.6, 0.3, eye);

    bool isRunning = true;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }
    if (!SDL_CreateWindowAndRenderer("CG1", scene.getWidth(), scene.getHeight(), 0, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    // Elements of the scene
    Vec3 k_sphere(0.7, 0.2, 0.2);
    Vec3 k_cilinder(0.2, 0.3, 0.8);
    Vec3 k_cone(0.8, 0.3, 0.2);
    Vec3 k_plane_c(0.2, 0.7, 0.2);
    Vec3 k_plane_f(0.3, 0.3, 0.7);
    Vec3 k_black(0, 0, 0);
    Vec3 center_sphere(0, 0, -1);
    //std::shared_ptr<Sphere> sphere = std::make_shared<Sphere>(0.4, center_sphere, Color(k_sphere, k_sphere, k_sphere, 10.0));
    //std::shared_ptr<Cilinder> cilinder = std::make_shared<Cilinder>(0.4, center_sphere, Vec3 {-1/std::sqrt(3), 1/std::sqrt(3), -1/std::sqrt(3)}, 0.4 * 3, true, true, Color(k_cilinder, k_cilinder, k_cilinder, 10));
    std::shared_ptr<Cone> cone = std::make_shared<Cone>(0.2, center_sphere, Vec3(0, 1, -1).norm(), 0.4, true, Color(k_cone, k_cone, k_cone, 10));
    std::shared_ptr<Plane> plane_c = std::make_shared<Plane>(Vec3 {0, -0.4, 0}, Vec3 {0, 1, 0}, Color(k_plane_c, k_black, k_plane_c, 1.0));
    std::shared_ptr<Plane> plane_f = std::make_shared<Plane>(Vec3 {0, 0, -2}, Vec3 {0, 0, 1}, Color(k_plane_f, k_black, k_plane_f, 1.0));
    std::shared_ptr<Light> light = std::make_shared<Light>(Vec3 {0, 0.6, -0.3}, Vec3 {0.7, 0.7, 0.7});
    scene.addLight(light);
    //scene.addObject(sphere);
    //scene.addObject(cilinder);
    scene.addObject(cone);
    scene.addObject(plane_c);
    scene.addObject(plane_f);
    scene.setAmbientLight(Vec3 {0.3, 0.3, 0.3});

    // Main loop
    while (isRunning) {
        // Exit
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }
        scene.drawFrame();
        SDL_RenderPresent(renderer);
    }

    // Exit gracefully
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
