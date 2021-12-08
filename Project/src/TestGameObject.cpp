#include "TestGameObject.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>
#include <SDL2/SDL.h>

namespace diva
{
    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(x, y, w, h)
    {
        texture = IMG_LoadTexture(system.renderer, (resPath + "images/dot40x40.bmp").c_str());
    }

    void TestGameObject::gameObjectUpdate()
    {
        // if (moveUp)
        // {
        //     rect.y--;
        // }
        // if (moveDown)
        // {
        //     rect.y++;
        // }
        if (moveLeft)
        {
            rect.x--;
        }
        if (moveRight)
        {
            rect.x++;
        }
    }

    void TestGameObject::draw() const
    {
        SDL_RenderCopy(system.renderer, texture, NULL, &rect);
    }

    void TestGameObject::keyDown(SDL_Event e)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
            // moveUp = false;
            // moveDown = true;
            rect.y++;
            break;
        case SDLK_UP:
            // moveDown = false;
            // moveUp = true;
            rect.y--;
            break;
        case SDLK_LEFT:
            moveRight = false;
            moveLeft = true;
            break;
        case SDLK_RIGHT:
            moveLeft = false;
            moveRight = true;
            break;
        }
    }

    void TestGameObject::keyUp(SDL_Event e)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
            moveDown = false;
            break;
        case SDLK_UP:
            moveUp = false;
            break;
        case SDLK_LEFT:
            moveLeft = false;
            break;
        case SDLK_RIGHT:
            moveRight = false;
            break;
        }
    }

    TestGameObject::~TestGameObject()
    {
        SDL_DestroyTexture(texture);
    }
};
