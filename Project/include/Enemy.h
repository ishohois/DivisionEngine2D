#if !defined(ENEMY_H)
#define ENEMY_H
#include "GameObject.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>
#include "Vector2D.h"
namespace diva
{

    class Enemy : public GameObject
    {
    private:
        /* data */
    public:
        Vector2D pos;
        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);

        Enemy(/* args */);

    };

}

#endif // ENEMY_H
