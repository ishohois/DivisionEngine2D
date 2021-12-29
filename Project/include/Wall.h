#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include "Vector2D.h"

namespace diva
{
    class Wall : public GameObject
    {
    private:
        Vector2D pos;
        BoxCollider2D collider;
        int w, h;
        int currentRow = 1, currentFrame = 1;
        int hp = 10;

    public:
        Wall(Vector2D *pos, int w, int h);
        virtual void gameObjectUpdate(float dt);
        virtual void draw() const;                     
        virtual void updateCollision(BoxCollider2D collider);
        BoxCollider2D& getCollider(){return collider;}
        ~Wall(){};
    };

};

#endif
