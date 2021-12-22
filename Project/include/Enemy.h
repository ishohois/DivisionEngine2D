#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "SDL2/SDL.h"
#include "Rigidbody2D.h"

namespace diva{
    class Enemy : public GameObject {//ärver från GameObject

        private:
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Vector2D position;
        RigidBody2D rb;
        BoxCollider2D collider;
        float degrees = 0;
        protected:
        
        public:
        Enemy(int x, int y, int w, int h);
        ~Enemy();
        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);
        void killEnemy();//ska anropas när fienden dör av en projektil el.dyl från spelaren.

    };
}

#endif