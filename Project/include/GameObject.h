#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>

namespace diva
{
    /*General base class for game objects in DivisionEngine*/
    class GameObject
    {
    private:
        // ta bort värdesemantik från klassen
        GameObject(const GameObject &other) = delete;
        const GameObject &operator=(const GameObject &other) = delete;
        SDL_Rect rect; // used for moving the character and collision detection

    protected:
        GameObject(int x, int y, int w, int h) : rect{x, y, w, h} {} // only available for sub classes of GameObject
    public:
        GameObject(){};
        SDL_Rect getRect() const { return rect; }
        virtual void gameObjectUpdate() = 0;    // abstract update function for game object called once per frame
        virtual void draw() const = 0;          // abstract function to be implemented by sub classes
        virtual void mouseDown(int x, int y){}; // function for mouse press
        virtual void mouseUp(int x, int y){};   // function for mouse release
        virtual void keyDown(){};               // function for key press
        virtual void keyUp(){};                 // function for key release
        virtual ~GameObject() = 0;
    };
};

#endif