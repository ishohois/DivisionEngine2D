#include "TestGameObject.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>
#include <SDL2/SDL.h>
#include "GameStateMachine.h"
#include "MenuState.h"

namespace diva
{
    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(x, y, w, h)
    {
        texture = IMG_LoadTexture(system.renderer, (resPath + "images/dot40x40.bmp").c_str());
        input = new Input(&rect);
        m_pGameStateMachine = new GameStateMachine();
        m_pGameStateMachine ->changeState(new MenuState());
    
    }

    void TestGameObject::gameObjectUpdate() // Update i unity gmaeObject
    {

        if (isMovingXAxel)
            input->horizontalMovement(speed);

        isMovingXAxel = false;

        // if (moveUp)
        // {
        //     rect.y--;
        // }
        // if (moveDown)
        // {
        //     rect.y++;
        // }
        // if (moveLeft)
        // {
        //     rect.x--;
        // }
        // if (moveRight)
        // {
        //     rect.x++;
        // }
    }

    void TestGameObject::draw() const
    {
        SDL_RenderCopy(system.renderer, texture, NULL, &rect);
    }

    void TestGameObject::keyDown(SDL_Event e) // VIll ju kallas i update.
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
            // moveUp = false;
            // moveDown = true;
            rect.y = rect.y + 2;
            break;
        case SDLK_UP:
            // moveDown = false;
            // moveUp = true;
            rect.y--;
            break;
        case SDLK_LEFT:
            isMovingXAxel = true;
            speed = -5;
            break;
        case SDLK_RIGHT:
            isMovingXAxel = true;
            speed = 5;
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
            //moveLeft = false;
            break;
        case SDLK_RIGHT:
            //moveRight = false;
            break;
        }
    }

    TestGameObject::~TestGameObject()
    {
        SDL_DestroyTexture(texture);
    }

};
