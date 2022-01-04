#include "Wall.h"
#include "TextureManager.h"
#include "SystemResources.h"
#include "CollisionHandler.h"
#include "GameManager.h"

namespace diva
{
    Wall::Wall(Vector2D pos, int w, int h) : GameObject(), pos(pos), collider(pos, w, h, "Wall"), w(w), h(h)
    {
        setTag("Wall");
        TextureManager::getInstance()->load(resPath + "images/Wall.png", "Wall", system.renderer);
        counter = damageTimer;
    }

    void Wall::gameObjectUpdate(float dt)
    {

        if (isDamaged)
        {
            counter -= (dt / 100);
        }

        if (counter <= 0)
        {
            hp--;
            counter = damageTimer;
            isDamaged = false;
        }

        if(hp <= 0){
            GameManager::getInstance()->remove(this);
            GameManager::getInstance()->removeCollider(collider);
        }
    }

    void Wall::draw() const
    {
        TextureManager::getInstance()->draw("Wall", pos.x, pos.y, w, h, system.renderer, 0, Spriteflip::FLIPNONE);
        TextureManager::getInstance()->drawFrame("Wall", pos.x, pos.y, w, h, currentRow, currentFrame, system.renderer, 0, Spriteflip::FLIPNONE);
    }

    void Wall::updateCollision(BoxCollider2D collision)
    {
        if (CollisionHandler::collisionDetection(collider, collision))
        {
            if (collision.getObjectTag() == "Enemy")
            {
                isDamaged = true;
            }
        }
    }

};