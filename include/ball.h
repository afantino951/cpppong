#ifndef BALL_H
#define BALL_H

#include<SDL.h>
#include<stdio.h>
#include "utils.h"

class Ball
{
private:
    int _x, _y;
    int _velX, _velY;

    SDL_Rect _collider;
public:
    static const int BALL_VEL = 2;

    void handleEvent(SDL_Event& e);
    void move();
    void move(SDL_Rect& wall);
    void render(SDL_Renderer* &renderer);
    
    Ball(int x, int y);
    ~Ball();
};


#endif /* BALL_H */