#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Rigidbody2D.h"

namespace diva
{ /* Denna klass tillhör spelet
    Detta är klassen som representerar fienden i spelet.
    Fienden kommer att följa spelaren och rotera mot den och träffar fienden spelaren så kommer denna att ta skada
    Om spelaren sjukter på fienden så dör denna och förstörs.

*/

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
        bool isDead;

    public:
        Enemy(int x, int y, int w, int h);
        ~Enemy();

        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);
        BoxCollider2D &getCollider() { return collider; };
        void setFollowPos(Vector2D *follow) { followPos = follow; }
        void rotateTowards();
    };

} // End of Diva

#endif