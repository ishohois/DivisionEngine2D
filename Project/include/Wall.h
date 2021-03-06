#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include "Vector2D.h"

namespace diva
{
    /*Den här klassen tillhör spelet
        Det är väggar som spelaren kan gömma sig bakom.
    */
    class Wall : public GameObject
    {
    private:
        Vector2D pos;
        BoxCollider2D collider;
        int w, h;
        int currentRow = 1, currentFrame = 1;
        int hp = 3;
        bool isDamaged = false;
        float damageTimer = 1.0f;
        float counter;

    public:
        Wall(Vector2D pos, int w, int h);
        virtual void gameObjectUpdate(float dt);
        virtual void draw() const;
        virtual void updateCollision(BoxCollider2D collider);
        BoxCollider2D &getCollider() { return collider; }
        ~Wall(){};
    };

};

#endif
