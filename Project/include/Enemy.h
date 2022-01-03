#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Rigidbody2D.h"

namespace diva
{

    class Enemy : public GameObject
    {
    private:
        /* data */
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Vector2D position;
        Vector2D *followPos;
        Vector2D dis;
        BoxCollider2D collider;
        RigidBody2D rb;
        int cr = 1, cf = 1;
        float degrees = 0;
        bool isWalking = false;
        bool isDead = false;

    public:
        Enemy(int x, int y, int w, int h);
        ~Enemy();

        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);
        BoxCollider2D &getCollider() { return collider; };
        void setFollowPos(Vector2D* follow){followPos = follow;}
        void rotateTowards();
    };

} // End of Diva

#endif