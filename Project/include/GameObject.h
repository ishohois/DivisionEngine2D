#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include "BoxCollider2D.h"

namespace diva
{
    /*  Denna klass tillhör spelmotorn
    Denna klass är en bas klass för alla spelobjekt i vår spelmotor. Den har virtuella funktioner som gör att den uppdateras av våran spelloop.
    Spel objekt kan ges an tag så att man kan använda den för att kolla kollion tillexempel. Eftersom konstruktorn är protected så kan man inte 
    instanziera denna klass, utan bara subklasser kommer åt konstruktorn. Vi har även sätt till att förhindra kopiering av klassen samt tilldelning. 
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