//
// Created by alexm on 2025-07-30.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <SDL3/SDL.h>

enum class TRIANGLE_TYPE {
    ACUTE,
    ISOSCELES,

};


class Triangle {
public:
    Triangle(SDL_FPoint p1,SDL_FPoint p2,SDL_FPoint p3, SDL_FColor color);
    void render(SDL_Renderer* renderer);

private:
    SDL_Vertex m_vertices[3];


};



#endif //TRIANGLE_H
