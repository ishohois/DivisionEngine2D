#ifndef LABEL_H
#define LABEL_H
#include "UIObject.h"
#include "SDL2/SDL.h"
#include <string>

namespace diva
{
    class Label : public UIObject{
       void setText(std::string input){}
       std::string getText(){}
    };
} 
