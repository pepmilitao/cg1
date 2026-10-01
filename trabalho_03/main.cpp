#include "include/Camera.h"
#include "include/Scene.h"
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
#include <memory>

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    Camera eye(Vec3 {0, 0, 0});
    Scene scene(&window, &renderer, 16.0 / 9.0, 800, 2.0, 1.0, eye);

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
    std::shared_ptr<Sphere> sphere1 = std::make_shared<Sphere>(0.5, Vec3 {-1.3, 0.0, -5.5}, Color(Vec3 {1.0, 0.0, 0.0}, Vec3 {0.5, 0.5, 0.5}, 5.0));
    std::shared_ptr<Sphere> sphere2 = std::make_shared<Sphere>(0.5, Vec3 {0.7, 0.0, -1.0}, Color(Vec3 {0.0, 1.0, 0.0}, Vec3 {0.5, 0.5, 0.5}, 5.0));
    std::shared_ptr<Light> light1 = std::make_shared<Light>(Vec3 {0, 5, -3}, Vec3 {0.7, 0.7, 0.7});
    std::shared_ptr<Light> light2 = std::make_shared<Light>(Vec3 {0, -5, 0}, Vec3 {0.7, 0.7, 0.7});
    scene.addLight(light1);
    scene.addLight(light2);
    scene.addObject(sphere1);
    scene.addObject(sphere2);

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
