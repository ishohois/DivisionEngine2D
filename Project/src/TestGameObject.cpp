#include "TestGameObject.h"
#include "SDL2/SDL.h"
#include <SystemResources.h>
#include "TextureManager.h"
#include "CollisionHandler.h"
#include "Contact.h"
#include "Input.h"

namespace diva
{
    bool grounded = false;
    bool jumping = false;
    float jumpTime = 0.5f;
    int currentRow = 1, currentFrame = 1;
    float degrees = 0;

    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Player")
    {
        TextureManager::getInstance()->load((resPath + "images/Block 2.png").c_str(), "test", system.renderer);
        rb.setGravity(0);
    }

    void TestGameObject::gameObjectUpdate(float dt) // Update i unity gameObject
    {
        rb.resetForce();

        if (InputHandler::getInstance()->getKeyDown(KEYS::W))
        {
            rb.applyForceY(-6.0f);
        }

        if (InputHandler::getInstance()->getKeyDown(KEYS::A))
        {

            rb.applyForceX(-6.0f);
        }

        if (InputHandler::getInstance()->getKeyDown(KEYS::S))
        {
            rb.applyForceY(6.0f);
        }
        
        if (InputHandler::getInstance()->getKeyDown(KEYS::D))
        {
            rb.applyForceX(6.0f);
        }

        if (InputHandler::getInstance()->getKeyDown(KEYS::SPACE))
        {
            jumping = true;
            rb.applyForceY(-30.0f);
        }
        if (jumping)
        {
            jumpTime -= (dt / 100);
            if (jumpTime <= 0)
            {
                jumpTime = 0.5f;
                jumping = false;
            }
        }

        float distX = collider.getCenterPoint().x - InputHandler::getInstance()->mousePos.x;
        float distY = InputHandler::getInstance()->mousePos.y - collider.getCenterPoint().y;
        float radians = (atan2(distY, distX));
        degrees = -radians * (180 / 3.14);

        if (InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::LMB))
        {
            std::cout << "distX: " << distX << std::endl;
            std::cout << "distY: " << distY << std::endl;
            std::cout << "radians: " << radians << std::endl;
            std::cout << "degrees: " << degrees << std::endl;
        }

        if (InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::MMB))
        {
            std::cout << "read middle mouse click" << std::endl;
        }

        if (InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::RMB))
        {
            std::cout << "read right mouse click" << std::endl;
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

            if (collision.getObjectTag() == "Wall")
            {
                std::cout << CollisionHandler::collisionResolution(collider, c) << std::endl;
                position += CollisionHandler::collisionResolution(collider, c) * 50;
            }
        }
    }

    void TestGameObject::draw() const
    {
        TextureManager::getInstance()->draw("test", (int)position.x, (int)position.y, 50, 50, system.renderer, degrees);
        TextureManager::getInstance()->drawFrame("test", (int)position.x, (int)position.y, 50, 50, currentRow, currentFrame, system.renderer, degrees);
    }

    TestGameObject::~TestGameObject()
    {
    }

};
