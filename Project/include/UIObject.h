#ifndef UIOBJECT_H
#define UIOBJECT_H
#include "GameObject.h"
#include <string>
#include <SDL2/SDL.h>

namespace diva {
    class UIObject : public GameObject{
        public:
        UIObject(){};
        virtual void setText(std::string input){};
        virtual std::string getText(){};

       virtual void gameObjectUpdate(float dt) = 0;

        void mouseDown(int x, int y){};
        void mouseUp(int x, int y){}; 
        void draw(){};
        //destruktor här eller i subklasserna?

    };
}


#endif