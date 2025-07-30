//
// Created by alexm on 2025-07-11.
//
#include <SDL3/SDL.h>
#include <cmath>
#include <memory>
#include <SDL3_ttf/SDL_ttf.h>

#include "../include/amugame/render/triangle.h"


constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

bool init(SDL_Window **window, SDL_Renderer **renderer) {
    bool success{true};

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_VIDEO initialization failed. Error: %s", SDL_GetError());
        success = false;
    }
    if (*window = SDL_CreateWindow("SDL3", SCREEN_WIDTH, SCREEN_HEIGHT, 0); *window == nullptr) {
        SDL_Log("Failed to create window. Error: %s", SDL_GetError());
        success = false;
    }
    if (*renderer = SDL_CreateRenderer(*window, nullptr); *renderer == nullptr) {
        SDL_Log("Failed to create renderer. Error: %s", SDL_GetError());
        success = false;
    }
    return success;
}

int main(int argc, const char *argv[]) {
    SDL_Window *gWindow{nullptr};
    SDL_Renderer *gRenderer{nullptr};
    TTF_Font *gFont{nullptr};
    if (!TTF_Init()) {
        SDL_Log("TTF_Init failed: %s", SDL_GetError());
        return 1;
    }
    gFont = TTF_OpenFont("assets/fonts/LibertinusMath-Regular.ttf", 24);
    if (gFont == nullptr) {
        SDL_Log("Failed to load font. Error: %s", SDL_GetError());
        return 1;
    }
    Uint64 currentTime{SDL_GetPerformanceCounter()};
    double deltaTime{0.00};
    double totalTime{0.00};
    SDL_FColor color = {255,0,255,255};

    if (!init(&gWindow, &gRenderer)) {
        SDL_Log("Failed to initialize program");
    }
    Triangle tri({100,100},{300,100},{200,300},color);
    // main loop
    bool quit{false};
    while (!quit) {
        Uint64 lastTime{0};
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }


        lastTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);


        SDL_RenderClear(gRenderer);
        tri.render(gRenderer);
        SDL_RenderPresent(gRenderer);
        SDL_Delay(16); // roughly 60 fps
    }
    if (gFont != nullptr) {
        TTF_CloseFont(gFont);
        gFont = nullptr;
    }
    TTF_Quit();
    SDL_Quit();
    return 0;
}
