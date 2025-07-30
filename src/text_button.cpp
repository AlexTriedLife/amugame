//
// Created by alexm on 2025-07-20.
//

#include "../include/text_button.h"

TextButton::TextButton(float x, float y, float w, float h, SDL_Renderer *renderer, TTF_Font *font,
                       const std::string &text, SDL_Color textColor) : Button(x, y, w, h), m_renderer(renderer),
                                                                       m_font(font), m_text(text),
                                                                       m_textColor(textColor) {
    updateTextTexture();
}

TextButton::~TextButton() = default;

void TextButton::updateTextTexture() {
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    if (m_text.empty()) {
        SDL_Log("Text button's text is empty");
        return;
    }
    if (!m_font) {
        SDL_Log("Text button's font failed to load");
        return;
    }
    SDL_Surface* textSurface = TTF_RenderText_Blended(m_font, m_text.c_str(), m_text.length(), m_textColor);
    if (textSurface == nullptr) {
        SDL_DestroySurface(textSurface);
        SDL_Log("Text button's text failed to render");
        return;
    }
    m_texture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
    if (m_texture == nullptr) {
        SDL_Log("Failed to create text texture from surface. Error: %s",SDL_GetError());
        SDL_DestroyTexture(m_texture);
        return;
    }
    // Center text
    m_textRect.w = static_cast<float>(textSurface->w);
    m_textRect.h = static_cast<float>(textSurface->h);
    m_textRect.x = m_rect.x + (m_rect.w - m_textRect.w) / 2.0f;
    m_textRect.y = m_rect.y + (m_rect.h - m_textRect.h) / 2.0f;

    SDL_DestroySurface(textSurface);
}

void TextButton::setText(const std::string &text) {
    m_text = text;
    updateTextTexture();
}

void TextButton::setTextColor(SDL_Color textColor) {
    m_textColor = textColor;
    updateTextTexture();
}

void TextButton::render(SDL_Renderer *renderer) {
    // this is the base of the button
    Button::render(renderer);
    if (m_texture != nullptr) {
        SDL_RenderTexture(renderer,m_texture, nullptr, &m_textRect );
    }
}


