#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Rigidbody2D.h"
namespace diva
{

    class Player : public GameObject
    {
    private:
        /* data */
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Vector2D position;
        BoxCollider2D collider;
        RigidBody2D rb;
        void getAngle();
        int cr = 1, cf = 1;
        int hp = 1;
        bool isDamaged = false;
        float damageTimer = 0.6f;
        float counter;
        float degrees = 0;
        bool isWalking = false;
        float shootTime = 0.1f;
        float shootCounter;

    public:
        Player(int x, int y, int w, int h);
        ~Player();

        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);
        Vector2D* getPosition() {return &position;}
        void shoot(float &sTime);
        BoxCollider2D &getCollider() { return collider; };
        int* getHP(){return &hp;}
    };

} // End of Diva

#endif