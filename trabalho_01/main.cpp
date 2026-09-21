#include "include/sphere.h"
#include "include/vec3.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

int main(int argc, char* argv[]) {
    // SDL variables
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    // Window specific variables
    const double distance_window = 10.0;
    const int width_window = 400;
    const int height_window = 400;
    const double radius_sphere = 300.0;
    const int n_columns = 200;
    const int n_lines = 200;
    const double size_x = (double) width_window / (double) n_columns;
    const double size_y = (double) height_window / (double) n_lines;
    bool isRunning = true;
    sphere s(radius_sphere, vec3(0.0, 0.0, -(distance_window + radius_sphere)));
    vec3 virtual_camera(0.0, 0.0, 0.0);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }
    if (!SDL_CreateWindowAndRenderer("Teste", width_window, height_window, 0, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }
    // Main loop
    while (isRunning) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (int l = 0; l < n_lines; ++l) {
            const double y = height_window / 2.0 - size_y / 2.0 - l * size_y;
            for (int c = 0; c < n_columns; ++c) {
                const double x = -width_window / 2.0 + size_x / 2.0 + c * size_x;
                ray r(virtual_camera, vec3 {x, y, -distance_window});
                if (s.intercepts(r)) {
                    //TODO: pintar todos os pixels do quadrado respectivo
                    SDL_RenderPoint(renderer, x + width_window / 2.0, -y + height_window / 2.0);
                }
            }
        }
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
