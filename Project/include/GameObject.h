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
    protected:
        //SDL_Rect srcRect; // used for moving the character and collision detection
        GameObject(){} // only available for sub classes of GameObject
    public:
        //GameObject(){};
        //SDL_Rect getRect() const { return rect; }
        virtual void gameObjectUpdate(float dt) = 0;    // abstract update function for game object called once per frame
        virtual void draw() = 0;          // abstract function to be implemented by sub classes
        virtual void mouseDown(int x, int y){}; // function for mouse press
        virtual void mouseUp(int x, int y){};   // function for mouse release
        virtual void keyDown(SDL_Event e){};               // function for key press
        virtual void keyUp(SDL_Event e){};                 // function for key release
        virtual ~GameObject(){};
    };
};

#endif