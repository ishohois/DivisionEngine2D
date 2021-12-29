#include "Bullet.h"
#include "TextureManager.h"
#include "SystemResources.h"

namespace diva

{

    Bullet::Bullet(int x, int y, int w, int h) : GameObject(), pos(x, y), collider(pos, w, h, "Bullet")
    {
        TextureManager::getInstance()->load((resPath + "images/Block.png").c_str(), "Bullet", system.renderer);
        rb.setGravity(0);
    }

    void Bullet::draw() const
    {
        TextureManager::getInstance()->draw("Bullet", pos.x, pos.y, 50, 50, system.renderer, 0, Spriteflip::FLIPNONE);
    }

    void Bullet::gameObjectUpdate(float dt)
    {
        rb.resetForce();
         rb.applyForceX(2.0f);
         rb.updatePhysics(dt);
         pos += rb.getRbPosition();

        if (moveCheckx >= 200)
        {
            std::cout << "Destroy meee" << std::endl;
            // Förstör Kulan.
        }
        moveCheckx++;
        collider.updateCollider();
    }

    void Bullet::updateCollision(BoxCollider2D collistion)
    {
    }

} // namespace diva
