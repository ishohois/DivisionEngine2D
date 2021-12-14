#include "TestGameObject.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>
#include "TextureManager.h"

namespace diva
{
    enum States
    {
        walkState,
        jumpState,
        standState
    };

    int currentRow = 1, currentFrame = 1;

    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Player"),
                                                                 srcRect{0, 0, 256, 256}, dstRect{(int)position.x, (int)position.y, w, h}
    {
        //texture = IMG_LoadTexture(system.renderer, (resPath + "images/Block 2.png").c_str());
        TextureManager::getInstance()->load((resPath + "images/char9.png").c_str(), "test", system.renderer);
        input = new Input(&dstRect);
    }

    void TestGameObject::gameObjectUpdate(float dt) // Update i unity gameObject
    {
        rb.setGravity(1.0f);
        rb.updatePhysics(dt);
        collider.updateCollider();
        currentFrame = int(((SDL_GetTicks() / 100) % 4));
        std::cout << currentFrame << "I GOU" << std::endl;
    }

    bool TestGameObject::checkCollision(const SDL_Rect &a, const SDL_Rect &b)
    {

        // sides of own collider
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        // calculate the sides of rect A
        leftA = a.x;
        rightA = a.x + a.w;
        topA = a.y;
        bottomA = a.y + a.h;

        //calculate the sides of rect B
        leftB = b.x;
        rightB = b.x + b.w;
        topB = b.y;
        bottomB = b.y + b.h;

        // if any of the sides from A are outside of B
        if (bottomA <= topB)
        {
            return false;
        }
        if (topA >= bottomB)
        {
            return false;
        }
        if (rightA <= leftB)
        {
            return false;
        }
        if (leftA >= rightB)
        {
            return false;
        }

        std::cout << "Kolliderar" << std::endl;
        return true;
    }

    void TestGameObject::draw() const
    {

        // dstRect.x = position.x;
        //  dstRect.y = position.y;
        //  SDL_RenderCopyEx(system.renderer, texture, &srcRect, &dstRect, 0, 0, flip);

        TextureManager::getInstance()->draw("test", (int)position.x, (int)position.y, 128, 133, system.renderer, flip);
        TextureManager::getInstance()->drawFrame("test", (int)position.x, (int)position.y, 128, 133, currentRow, currentFrame, system.renderer,flip);
    }

    void TestGameObject::keyDown(SDL_Event e) // VIll ju kallas i update.
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
            position.y += 5.0f;
            break;
        case SDLK_UP:
            position.y -= 5.0f;
            break;
        case SDLK_LEFT:
            position.x -= 5.0f;
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case SDLK_RIGHT:
            flip = SDL_FLIP_NONE;
            position.x += 5.0f;
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
        // SDL_DestroyTexture(texture);
        delete input;
    }

};
