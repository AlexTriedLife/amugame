//
// Created by alexm on 2025-07-30.
//

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <SDL3/SDL.h>

class InputManager {
public:
    // Keyboard Management
    bool isKeyDown(SDL_Scancode key);
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
    // Mouse Management
    bool isMouseButtonDown(SDL_Scancode key);
    bool isMouseButtonPressed(SDL_Scancode key);
    bool isMouseButtonReleased(SDL_Scancode key);
    bool isMouseButtonHeld(SDL_Scancode key);

    InputManager();
    ~InputManager();
private:
};

#endif //INPUT_MANAGER_H
