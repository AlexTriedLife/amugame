//
// Created by alexm on 2025-07-11.
//

#include "amugame/ui/button.h"

Button::Button(float x, float y, float w, float h) {
    m_rect = {x,y,w,h};
}

Button::~Button() = default;

void Button::render(SDL_Renderer *renderer) {

    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // gray
    SDL_RenderFillRect(renderer, &m_rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white border
    SDL_RenderRect(renderer, &m_rect);
}

void Button::handleEvent(SDL_Event &e) {
    if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN && e.button.button == SDL_BUTTON_LEFT) {
        auto mouseX = static_cast<float>(e.button.x);
        auto mouseY = static_cast<float>(e.button.y);
        if (isInside(mouseX, mouseY) && m_onClick) {
            m_onClick();
        }
    }
}


void Button::setCallback(std::function<void()> callback) {
    m_onClick = callback;
}

void Button::setPosition(float x, float y) {
    m_rect.x = x;
    m_rect.y = y;
}

void Button::setSize(float w, float h) {
    m_rect.w = w;
    m_rect.h = h;
}

SDL_FRect Button::getRect() const {
    return m_rect;
}

// const std::string & Button::getId() const {
//     return m_id;
// }
//
// void Button::setId(const std::string &id) {
//     m_id = id;
// }

bool Button::isInside(float x, float y) {
    // top left corner is (x,y)
    // top right corner is (x + width,y)
    // bottom left corner is (x, y + height)
    // bottom right corner is (x + width, y + height)

    if (x >= m_rect.x && x <= m_rect.x + m_rect.w && y >= m_rect.y && y <= m_rect.y + m_rect.h ) {
        return true;
    }
    return false;
}
