#include "Wall.h"
#include "TextureManager.h"
#include "SystemResources.h"
#include "CollisionHandler.h"

namespace diva
{
    Wall::Wall(Vector2D *pos, int w, int h) : GameObject(), pos(*pos), collider(*pos, w, h, "Wall"), w(w), h(h)
    {
        TextureManager::getInstance()->load(resPath + "images/Block.png", "Wall", system.renderer);
    }

    void Wall::gameObjectUpdate(float dt)
    {
    }

    void Wall::draw() const
    {
        TextureManager::getInstance()->draw("Wall", pos.x, pos.y, w, h, system.renderer, 0);
        TextureManager::getInstance()->drawFrame("Wall", pos.x, pos.y, w, h, currentRow, currentFrame, system.renderer, 0);
    }

    void Wall::updateCollision(BoxCollider2D collision)
    {
        if (CollisionHandler::collisionDetection(collider, collision))
        {
            if (collision.getObjectTag() == "Player")
            {
                hp -= 1;

                std::cout << "ouch..wall starts to crumble.." << hp << std::endl;
            }
        }
    }

};