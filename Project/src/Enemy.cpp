#include "Enemy.h"
#include "SDL2/SDL.h"
#include "SystemResources.h"
#include "TextureManager.h"
#include "CollisionHandler.h"
#include "Contact.h"

namespace diva
{

    //anropa Enemy:s ktr som ärver från GameObject
    Enemy::Enemy(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Enemy")
    {
        TextureManager::getInstance()->load((resPath + "images/Dude.png").c_str(), "enemyTest", system.renderer);
        rb.setGravity(3.0f);
    }
    void Enemy::draw() const
    {
        TextureManager::getInstance()->draw("enemyTest",
        (int)position.x, (int)position.y, 40, 40, system.renderer, degrees);
    }
    void Enemy::gameObjectUpdate(float dt)
    {
    }
    void Enemy::updateCollision(BoxCollider2D collision)
    {
    }

    void Enemy::killEnemy()
    {
    }

    Enemy::~Enemy()
    {
    }

}