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
        // laddar in spriten som ska användas samt sätter ett ID så att man kan hämta texuren från en map. sätter även en renderare.
        TextureManager::getInstance()->load((resPath + "images/PlayerSprite/RBS.png").c_str(), "Player", system.renderer);
        rb.setGravity(0); // Eftersom spelet är topdown och vi fortfarande vill använda våran ridigbody klass så sätter vi gravity till 0.
    }

    void Player::gameObjectUpdate(float dt)
    {
        rb.resetForce();

        //[Uträkning för vilken grad som spriten ska titta på]
        getAngel();

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

        if (InputHandler::getInstance()->getMouseButton(MOUSEBUTTON::LMB))
        {
            std::cout << "FIRE!!" << std::endl;
            //Bullet *bull =  new Bullet(position.x,position.y,10,10); // Hur lägger vi till den i GameManager?
            


        }

        // När spelaren sjukter så ska den instanziera en annan klass som är av typ "Skott" eller liknande
        cf = int(((SDL_GetTicks() / 100) % 2));

        rb.updatePhysics(dt);
        position.x += rb.getRbPosition().x;
        rb.updatePhysics(dt);
        position.y += rb.getRbPosition().y;
        if (rb.getVelocity().x != 0 || rb.getVelocity().y != 0)
        {
            isWalking = true;
        }
        else
        {
            isWalking = false;
        }

        collider.updateCollider();
    }

    void Player::updateCollision(BoxCollider2D collision)
    {
    }

    void Player::draw() const
    {
        // OM player Velocity == 0
        
        TextureManager::getInstance()->draw("Player", (int)position.x, (int)position.y, 57, 43, system.renderer, degrees, Spriteflip::HORIZONTALFLIP);
        if(isWalking)
        TextureManager::getInstance()->drawFrame("Player", (int)position.x, (int)position.y, 57, 43, cr, cf, system.renderer, degrees, Spriteflip::HORIZONTALFLIP);
    }

    void Player::getAngel()
    {
        float distX = collider.getCenterPoint().x - InputHandler::getInstance()->mousePos.x;
        float distY = InputHandler::getInstance()->mousePos.y - collider.getCenterPoint().y;
        float radians = (atan2(distY, distX));
        degrees = -radians * (180 / 3.14);
    }

    Player::~Player()
    {
    }

}
