#include "TestGameObject.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>


namespace diva
{
    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(), position(x, y), srcRect{0,0, w, h}, dstRect{(int)position.x, (int)position.y, w, h} 
    {
        texture = IMG_LoadTexture(system.renderer, (resPath + "images/dot40x40.bmp").c_str());
        input = new Input(&dstRect);
    }

    void TestGameObject::gameObjectUpdate() // Update i unity gmaeObject
    {
        position.x += 1;
    }

    void TestGameObject::draw()
    {
        dstRect.x = position.x;
        dstRect.y = position.y;
        SDL_RenderCopyEx(system.renderer, texture, &srcRect, &dstRect, 0,0, flip);
    }

    void TestGameObject::keyDown(SDL_Event e) // VIll ju kallas i update.
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
