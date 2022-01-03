#include "Enemy.h"
#include <SystemResources.h>
#include "TextureManager.h"
#include "CollisionHandler.h"
#include "Contact.h"
#include "Input.h"
#include "GameManager.h"

namespace diva
{

    /*
    
 */
    Enemy::Enemy(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Enemy")
    {
        setTag("Enemy");
        // laddar in spriten som ska användas samt sätter ett ID så att man kan hämta texuren från en map. sätter även en renderare.
        TextureManager::getInstance()->load((resPath + "images/Block.png").c_str(), "Enemy", system.renderer);
        rb.setGravity(0); // Eftersom spelet är topdown och vi fortfarande vill använda våran ridigbody klass så sätter vi gravity till 0.
    }

    void Enemy::gameObjectUpdate(float dt)
    {

        if (!followPos)
        {
            return;
        }

        rb.resetForce();

        Vector2D dis = *followPos - position;

        rb.applyForce(dis.normalize() * 0.02 * (fabs(dis.x) > fabs(dis.y) ? fabs(dis.x) : fabs(dis.y)));

        rb.updatePhysics(dt);
        position += rb.getRbPosition();

        collider.updateCollider();
    }

    void Enemy::updateCollision(BoxCollider2D collision)
    {
        Contact c;
        if (CollisionHandler::collisionDetection(collider, collision, c))
        {
            if (collision.getObjectTag() == "Bullet")
            {
                isDead = true;
                GameManager::getInstance()->remove(this);
                GameManager::getInstance()->removeCollider(collider);
            }

            if(collision.getObjectTag() == "Wall"){
                position += CollisionHandler::collisionResolution(collider, c);
            }
        }
    }

    void Enemy::draw() const
    {
        if (!isDead)
        {
            TextureManager::getInstance()->draw("Enemy", (int)position.x, (int)position.y, 50, 50, system.renderer, 0, Spriteflip::FLIPNONE);
            TextureManager::getInstance()->drawFrame("Enemy", (int)position.x, (int)position.y, 50, 50, cr, cf, system.renderer, 0, Spriteflip::FLIPNONE);
        }
    }

    Enemy::~Enemy()
    {
    }

}
