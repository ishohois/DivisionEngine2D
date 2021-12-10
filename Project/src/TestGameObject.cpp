#include "TestGameObject.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>

namespace diva
{
    enum States{
        walkState, jumpState, standState
    };

    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(), position(x, y),
                                                                 srcRect{0, 0, 375, 512}, dstRect{(int)position.x, (int)position.y, w, h}
    {
        texture = IMG_LoadTexture(system.renderer, (resPath + "images/Dude.png").c_str());
        input = new Input(&dstRect);
    }

    void TestGameObject::gameObjectUpdate(float dt) // Update i unity gameObject
    {
        rb.setGravity(1.0f);
        rb.updatePhysics(dt);

        States currentState;
        currentState = walkState;
    }

    void TestGameObject::draw()
    {
        dstRect.x = position.x;
        dstRect.y = position.y;
        SDL_RenderCopyEx(system.renderer, texture, &srcRect, &dstRect, 0, 0, flip);
    }

    void TestGameObject::keyDown(SDL_Event e) // VIll ju kallas i update.
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
            rb.setGravity(0.5f);
            break;
        case SDLK_UP:
            rb.setGravity(9);
            break;
        case SDLK_LEFT:

            break;
        case SDLK_RIGHT:

            break;
        }
    }

    void TestGameObject::keyUp(SDL_Event e)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:

            break;
        case SDLK_UP:

            break;
        case SDLK_LEFT:

            break;
        case SDLK_RIGHT:

            break;
        }
    }

    TestGameObject::~TestGameObject()
    {
        SDL_DestroyTexture(texture);
        delete input;
    }

};
