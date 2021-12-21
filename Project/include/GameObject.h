#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include "BoxCollider2D.h"

namespace diva
{
    /*General base class for game objects in DivisionEngine*/
    class GameObject
    {
    private:
        // ta bort värdesemantik från klassen
        GameObject(const GameObject &other) = delete;
        const GameObject &operator=(const GameObject &other) = delete;
    protected:
        GameObject(){} // only available for sub classes of GameObject
    public:
        virtual void gameObjectUpdate(float dt) = 0;    // abstract update function for game object called once per frame
        virtual void draw() const = 0;          // abstract function to be implemented by sub classes
        virtual void updateCollision(BoxCollider2D collider){};
        virtual ~GameObject(){};
    };
};

#endif