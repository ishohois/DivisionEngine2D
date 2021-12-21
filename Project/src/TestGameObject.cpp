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

    TestGameObject::TestGameObject(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Player")
    {
        TextureManager::getInstance()->load((resPath + "images/Block 2.png").c_str(), "test", system.renderer);
        rb.setGravity(3.0f);
    }

    void TestGameObject::gameObjectUpdate(float dt) // Update i unity gameObject
    {
        rb.resetForce();

        if (InputHandler::getInstance()->getKeyDown(KEYS::A))
        {

            rb.applyForceX(-6.0f);
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

        if(InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::LMB)){
            std::cout << "read left mouse click" << std::endl;
        }

          if(InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::MMB)){
            std::cout << "read middle mouse click" << std::endl;
        }

        if(InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::RMB)){
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
        }
    }

    void TestGameObject::draw() const
    {
        TextureManager::getInstance()->draw("test", (int)position.x, (int)position.y, 50, 50, system.renderer);
        TextureManager::getInstance()->drawFrame("test", (int)position.x, (int)position.y, 50, 50, currentRow, currentFrame, system.renderer);
    }

    TestGameObject::~TestGameObject()
    {
    }

};
