//
// Created by alexm on 2025-07-29.
//

#ifndef LABEL_H
#define LABEL_H
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>



struct Label {
    std::string text;
    SDL_Color textColor;
    TTF_Font *font;
    float posX, posY;
    SDL_Texture *texture;
    SDL_FRect textRect;
};

Label createLabel(SDL_Renderer* renderer, const std::string &text,  TTF_Font *font,SDL_Color textColor,float x, float y);
void renderLabel(SDL_Renderer* renderer, const Label &label);
void destroyLabel(Label& label);
void updateLabelText(SDL_Renderer* renderer, Label &label, const std::string &new_text);



#endif //LABEL_H
