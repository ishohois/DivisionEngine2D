#include "Player.h"
#include <SystemResources.h>
#include "TextureManager.h"
#include "CollisionHandler.h"
#include "Contact.h"
#include "Input.h"
#include "GameManager.h"
#include "Bullet.h"

namespace diva
{

    /*
    
 */
    Player::Player(int x, int y, int w, int h) : GameObject(), position(x, y), collider(position, w, h, "Player")
    {
        setTag("Player");
        // laddar in spriten som ska användas samt sätter ett ID så att man kan hämta texuren från en map. sätter även en renderare.
        TextureManager::getInstance()->load((resPath + "images/PlayerSprite/RBS.png").c_str(), tag, system.renderer);
        rb.setGravity(0); // Eftersom spelet är topdown och vi fortfarande vill använda våran ridigbody klass så sätter vi gravity till 0.
        shootCounter = shootTime;
        counter = damageTimer;
    }

    void Player::gameObjectUpdate(float dt)
    {

        rb.resetForce();

        //[Uträkning för vilken grad som spriten ska titta på]
        getAngle();

        // Kolla imputs för att röra spelaren.
        if (InputHandler::getInstance()->getKeyDown(KEYS::A))
        {
            rb.applyForceX(-6.0f);
        }

        if (InputHandler::getInstance()->getKeyDown(KEYS::D))
        {
            rb.applyForceX(6.0f);
        }

        if (InputHandler::getInstance()->getKeyDown(KEYS::W))
        {
            rb.applyForceY(-6.0f);
        }
        if (InputHandler::getInstance()->getKeyDown(KEYS::S))
        {
            rb.applyForceY(6.0f);
        }

        shootCounter -= (dt / 100);
        if (InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::LMB))
        {
            shoot(shootCounter);
        }

        // När spelaren sjukter så ska den instanziera en annan klass som är av typ "Skott" eller liknande
        cf = int(((SDL_GetTicks() / 100) % 2));


        rb.updatePhysics(dt);
        position += rb.getRbPosition();

        if (rb.getVelocity().x != 0 || rb.getVelocity().y != 0)
        {
            isWalking = true;
        }
        else
        {
            isWalking = false;
        }
        collider.updateCollider();

        if (isDamaged)
        {
            counter -= (dt / 100);
        }

        if (counter <= 0)
        {
            hp--;
            counter = damageTimer;
            isDamaged = false;
            std::cout << "Spelarens hp: " << hp << std::endl;
        }

        if(hp <= 0){
            GameManager::getInstance()->remove(this);
            GameManager::getInstance()->removeCollider(collider);
        }

    }

    void Player::updateCollision(BoxCollider2D collision)
    {
        Contact c;

        if(CollisionHandler::collisionDetection(collider, collision, c)){
            if(collision.getObjectTag() == "Enemy"){
                isDamaged = true;
            }

            if(collision.getObjectTag() == "Wall"){
                position += CollisionHandler::collisionResolution(collider, c);
            }
        }
    }

    void Player::draw() const
    {
        // OM player Velocity == 0

        TextureManager::getInstance()->draw(tag, (int)position.x, (int)position.y, 57, 43, system.renderer, degrees, Spriteflip::HORIZONTALFLIP);
        if (isWalking)
            TextureManager::getInstance()->drawFrame(tag, (int)position.x, (int)position.y, 57, 43, cr, cf, system.renderer, degrees, Spriteflip::HORIZONTALFLIP);
    }

    void Player::getAngle()
    {
        float distX = collider.getCenterPoint().x - InputHandler::getInstance()->mousePos.x;
        float distY = InputHandler::getInstance()->mousePos.y - collider.getCenterPoint().y;
        float radians = (atan2(distY, distX));
        degrees = -radians * (180 / 3.14);
    }

    void Player::shoot(float &sTime)
    {
        Bullet *bull = nullptr;

        if (sTime >= 0)
        {
            return;
        }

        Vector2D v{(float)InputHandler::getInstance()->mousePos.x, (float)InputHandler::getInstance()->mousePos.y};
        Vector2D dir = v - position;
        bull = new Bullet(position, v); // Hur lägger vi till den i GameManager?
        GameManager::getInstance()->addCollider(bull->getCollider());
        sTime = shootTime;
        bull = nullptr;
    }

    Player::~Player()
    {
    }

}
