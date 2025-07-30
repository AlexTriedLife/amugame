//
// Created by alexm on 2025-07-30.
//

#include "../include/triangle.h"

Triangle::Triangle(const SDL_FPoint p1, const SDL_FPoint p2, const SDL_FPoint p3, const SDL_FColor color) {
    m_vertices[0] = {p1,color, SDL_FPoint{0,0}};
    m_vertices[1] = {p2,color, SDL_FPoint{0,0}};
    m_vertices[2] = {p3,color, SDL_FPoint{0,0}};
}

void Triangle::render(SDL_Renderer *renderer) {
    SDL_RenderGeometry(renderer, nullptr, m_vertices,3,nullptr,0 );
}
