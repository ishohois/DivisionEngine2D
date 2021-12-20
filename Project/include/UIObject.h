#ifndef UIOBJECT_H
#define UIOBJECT_H
#include "GameObject.h"
#include <string>
#include <SDL2/SDL.h>

namespace diva {
    class UIObject : public GameObject{
        public:
        virtual void setText(std::string input){};
        virtual std::string getText(){};
        std::string textToDisplay;

        void mouseDown(int x, int y){};
        void mouseUp(int x, int y){}; 
        void draw(){};
        //destruktor här eller i subklasserna?

    };
}


#endif