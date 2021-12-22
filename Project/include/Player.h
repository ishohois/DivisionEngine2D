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
        void getAngel();
        int cr = 1, cf = 1;
        float degrees = 0;
        bool isWalking = false;

    public:
        Player(int x, int y, int w, int h);
        ~Player();

        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);

        BoxCollider2D &getCollider() { return collider; };
    };

} // End of Diva

#endif