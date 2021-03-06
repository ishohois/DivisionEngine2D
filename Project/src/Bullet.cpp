#include "Bullet.h"
#include "TextureManager.h"
#include "SystemResources.h"
#include "GameManager.h"

namespace diva

{

    Bullet::Bullet(Vector2D origin, Vector2D target) : GameObject(), pos(origin), collider(pos, 10, 10, "Bullet")
    {
        GameManager::getInstance()->add(this);
        GameManager::getInstance()->addCollider(collider);
        TextureManager::getInstance()->load((resPath + "images/bullet.png").c_str(), "Bullet", system.renderer);
        rb.setGravity(0);
        dir = target - origin;
        dir.normalize();
        fired = true;
    }

    void Bullet::draw() const
    {
        if (!destroy())
            TextureManager::getInstance()->draw("Bullet", pos.x, pos.y, 10, 10, system.renderer, 0, Spriteflip::FLIPNONE);
    }

    void Bullet::gameObjectUpdate(float dt)
    {
        rb.resetForce();

        if (fired)
        {
            rb.applyForce(dir * 10.0f);
        }

        rb.updatePhysics(dt);
        pos += rb.getRbPosition();

        collider.updateCollider();

        if (destroy())
        {
            GameManager::getInstance()->remove(this);
            GameManager::getInstance()->removeCollider(collider);
        }
    }

    void Bullet::updateCollision(BoxCollider2D collistion)
    {
    }

    bool Bullet::destroy() const
    {
        return pos.x <= 0 || pos.x >= SCREENWIDTH || pos.y <= 0 || pos.y >= SCREENHEIGHT;
    }

    Bullet::~Bullet()
    {
    }

} // namespace diva
