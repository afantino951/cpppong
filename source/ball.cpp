#include "ball.h"

void
Ball::handleEvent(SDL_Event& e) {
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: _velY -= BALL_VEL; break;
            case SDLK_DOWN: _velY += BALL_VEL; break;
            case SDLK_LEFT: _velX -= BALL_VEL; break;
            case SDLK_RIGHT: _velX += BALL_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: _velY += BALL_VEL; break;
            case SDLK_DOWN: _velY -= BALL_VEL; break;
            case SDLK_LEFT: _velX += BALL_VEL; break;
            case SDLK_RIGHT: _velX -= BALL_VEL; break;
        }
    }
}

void
Ball::move() {
    _x += _velX;
    _y += _velY;

    // Check if collided with wall and revert the move
    if ((_x < 0) || (_x + BALL_WIDTH > SCREEN_WIDTH)) {
        _x -= _velX;
    }
    if ((_y < 0) || (_y + BALL_HEIGHT > SCREEN_HEIGHT)) {
        _y -= _velY;
    }
}

void
Ball::move(SDL_Rect& wall) {
    _x += _velX;
    _y += _velY;

    // Check if collided with wall and revert the move
    if ((_x < 0) || (_x + BALL_WIDTH > SCREEN_WIDTH)) {
        _x -= _velX;
    }
    if ((_y < 0) || (_y + BALL_HEIGHT > SCREEN_HEIGHT)) {
        _y -= _velY;
    }
}

void 
Ball::render(SDL_Renderer* &renderer) {
    //Render red filled quad
    SDL_Rect fillRect = {_x, _y, BALL_WIDTH, BALL_HEIGHT};
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );		
    SDL_RenderFillRect( renderer, &fillRect );
}

Ball::Ball(int x, int y)
    :_x(x), _y(y)
{
    _velX = 0;
    _velY = 0;
}

Ball::~Ball()
{
}
