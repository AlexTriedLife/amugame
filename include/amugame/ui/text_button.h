//
// Created by alexm on 2025-07-20.
//

#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include "amugame/ui/button.h"


class TextButton : public Button {
public:
    TextButton(float x, float y, float w, float h, SDL_Renderer *renderer, TTF_Font *font, const std::string &text,
               SDL_Color textColor = {0, 0, 0, 255});
    ~TextButton() override;
    void render(SDL_Renderer *renderer) override;
    void updateTextTexture();

    void setText(const std::string &text);
    void setTextColor(SDL_Color textColor);
private:
    SDL_Renderer *m_renderer;
    TTF_Font *m_font;
    std::string m_text;
    SDL_Color m_textColor;

    SDL_Texture *m_texture = nullptr;
    SDL_FRect m_textRect;
};


#endif //TEXT_BUTTON_H
