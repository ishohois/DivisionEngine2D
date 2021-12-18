#include "TestGameObject.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>
#include "TextureManager.h"
#include "CollisionHandler.h"
#include "Contact.h"

namespace diva
{
    enum States
    {
        walkState,
        jumpState,
        standState
    };

    bool grounded = false;
    bool moveRight = false;
    bool moveLeft = false;
    bool jump = false;
    float jumpTime = 0.5f;
    int currentRow = 1, currentFrame = 1;

    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Player"),
                                                                 srcRect{0, 0, 256, 256}, dstRect{(int)position.x, (int)position.y, w, h}
    {
        //texture = IMG_LoadTexture(system.renderer, (resPath + "images/Block 2.png").c_str());
        TextureManager::getInstance()->load((resPath + "images/Block 2.png").c_str(), "test", system.renderer);
        input = new Input(&dstRect);
        rb.setGravity(3.0f);
    }

    void TestGameObject::gameObjectUpdate(float dt) // Update i unity gameObject
    {
        rb.resetForce();

        if (moveLeft)
        {
            rb.applyForceX(-6.0f);
        }

        if (moveRight)
        {
            rb.applyForceX(6.0f);
        }

        if (jump)
        {
            rb.applyForceY(-15.0f);
            jumpTime -= (dt / 100);

            if (jumpTime <= 0)
            {
                grounded = false;
                jumpTime = 0.5f;
                jump = false;
            }
        }

        rb.updatePhysics(dt);
        position.y += rb.getRbPosition().y;

        rb.updatePhysics(dt);
        position.x += rb.getRbPosition().x;
        //currentFrame = int(((SDL_GetTicks() / 100) % 4));
        collider.updateCollider();
    }

    void TestGameObject::updateCollision(BoxCollider2D collision)
    {
        Contact c;

        if (CollisionHandler::collisionDetection(collider, collision, c))
        {
            if (collision.getObjectTag() == "Collision")
            {
                grounded = true;
                position += CollisionHandler::collisionResolution(collider, c);
            }
            else
            {
                grounded = false;
            }
        }
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
        TextureManager::getInstance()->draw("test", (int)position.x, (int)position.y, 50, 50, system.renderer);
        TextureManager::getInstance()->drawFrame("test", (int)position.x, (int)position.y, 50, 50, currentRow, currentFrame, system.renderer);
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
            moveLeft = true;
            break;
        case SDLK_RIGHT:
            moveRight = true;
            break;
        case SDLK_SPACE:
            jump = true;
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
            moveLeft = false;
            break;
        case SDLK_RIGHT:
            moveRight = false;
            break;
        }
    }

    TestGameObject::~TestGameObject()
    {
        // SDL_DestroyTexture(texture);
        delete input;
    }

};
