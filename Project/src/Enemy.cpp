#include "Enemy.h"
#include "TextureManager.h"
#include "SystemResources.h"
namespace diva
{

    Enemy::Enemy()
    {
        TextureManager::getInstance()->load(resPath + "images/Space.png", "Enemy", system.renderer);
    }

    void Enemy::draw() const
    {

        TextureManager::getInstance()->draw("Enemy", (int)pos.x, (int)pos.y, 512, 512, system.renderer);
    }

    void Enemy::gameObjectUpdate(float dt)
    {

    }

}
