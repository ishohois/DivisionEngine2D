#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include "BoxCollider2D.h"

namespace diva
{
    /* 
    Denna klass är vårat gameobject, för att skapa ett spelobjekt i spelvärlden ska man använda denna klass. Den ser till att värdesamantiks tas bort och den har 
    virtuella funktioner som tvingar objekt som ärver från klassen att implementera de på något sätt. Man kan ge objekt en tag.

     */
    /*General base class for game objects in DivisionEngine*/
    class GameObject
    {
    private:
        // ta bort värdesemantik från klassen
        GameObject(const GameObject &other) = delete;
        const GameObject &operator=(const GameObject &other) = delete;

    protected:
        GameObject() {} // only available for sub classes of GameObject
        std::string tag;
    public:
        virtual void gameObjectUpdate(float dt) = 0; // abstract update function for game object called once per frame
        virtual void draw() const = 0;               // abstract function to be implemented by sub classes
        virtual void updateCollision(BoxCollider2D collider){};
        void setTag(std::string tagName) { tag = tagName; }
        std::string getTag() const { return tag; }
        virtual ~GameObject(){};
    };
};

#endif