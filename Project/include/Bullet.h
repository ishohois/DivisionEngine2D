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
        Vector2D pos;
        Vector2D dir;
        BoxCollider2D collider;
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        RigidBody2D rb;
        int currentRow = 1, currentFrame = 1;
        bool fired = false;

    public:
        Bullet(Vector2D pos, Vector2D target);

        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);
        BoxCollider2D &getCollider() { return collider; }
        bool destroy() const;

        ~Bullet();
    };

}

#endif // BULLET_H
