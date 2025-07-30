//
// Created by alexm on 2025-07-11.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <SDL3/SDL.h>
#include <functional>
#include <string>

#include "button.h"


class Button {
public:
    Button(float x, float y, float w, float h );
    virtual ~Button();
    virtual void render(SDL_Renderer *renderer);
    void handleEvent(SDL_Event &e);

    // Getters and setters
    void setCallback(std::function<void()> callback);
    void setPosition(float x, float y);
    void setSize(float w, float h);
    SDL_FRect getRect() const;
    // const std::string &getId() const;
    // void setId(const std::string &id);
    virtual bool isInside(float x, float y);

protected:
    SDL_FRect m_rect;
    std::function<void()> m_onClick;
    // std::string m_id;



};



#endif //BUTTON_H
