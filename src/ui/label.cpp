//
// Created by alexm on 2025-07-29.
//

#include "../../include/amugame/ui/label.h"

Label createLabel(SDL_Renderer *renderer, const std::string &text, TTF_Font *font, const SDL_Color textColor, float x,
                  float y) {
    Label label;
    label.text = text;
    label.font = font;
    label.textColor = textColor;
    label.posX = x;
    label.posY = y;
    label.texture = nullptr;

    if (SDL_Surface* surface = TTF_RenderText_Solid(font,text.c_str(),text.length(),textColor)) {
        label.texture = SDL_CreateTextureFromSurface(renderer,surface);
        label.textRect = {x,y,static_cast<float>(surface->w),static_cast<float>(surface->h)};
        SDL_DestroySurface(surface);
    }
    return label;
}

void renderLabel(SDL_Renderer *renderer, const Label &label) {
    if (label.texture) {
        SDL_RenderTexture(renderer,label.texture,nullptr,&label.textRect);
    }
}

void destroyLabel(Label &label) {
    if (label.texture) {
        SDL_DestroyTexture(label.texture);
        label.texture = nullptr;
    }
}

void updateLabelText(SDL_Renderer *renderer, Label &label, const std::string &new_text) {

    if (label.texture != nullptr) {
        SDL_DestroyTexture(label.texture);
        label.texture = nullptr;
    }
    if (label.text.empty()) {
        SDL_Log("Text button's text is empty");
        return;
    }
    if (!label.font) {
        SDL_Log("Text button's font failed to load");
        return;
    }
    SDL_Surface* textSurface = TTF_RenderText_Blended(label.font, new_text.c_str(), label.text.length(), label.textColor);
    if (textSurface == nullptr) {
        SDL_DestroySurface(textSurface);
        SDL_Log("Text button's text failed to render");
        return;
    }
    label.texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (label.texture == nullptr) {
        SDL_Log("Failed to create text texture from surface. Error: %s",SDL_GetError());
        SDL_DestroyTexture(label.texture);
        return;
    }
    // Center text
    label.textRect.w = static_cast<float>(textSurface->w);
    label.textRect.h = static_cast<float>(textSurface->h);
    label.textRect.x = label.textRect.x + (label.textRect.w - label.textRect.w) / 2.0f;
    label.textRect.y = label.textRect.y + (label.textRect.h - label.textRect.h) / 2.0f;

    SDL_DestroySurface(textSurface);
}
