#if !defined(BULLET_H)
#define BULLET_H

#include "GameObject.h"
#include "BoxCollider2D.h"
#include "Rigidbody2D.h"

namespace diva
{
    class Bullet : public GameObject
    {
    private:
    BoxCollider2D collider;
    Vector2D pos;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    RigidBody2D rb;
    int currentRow = 1, currentFrame = 1;
    int moveCheckx = 0, moceChecky = 0;


    public:
        Bullet(int x, int y, int w, int h);

        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);

        ~Bullet(){
            delete [] this;
            
        }
    };

}

#endif // BULLET_H
