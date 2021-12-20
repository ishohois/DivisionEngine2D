#include "UIObject.h"
#include "GameObject.h"
#include <string>

namespace diva{
    void UIObject::setText(std::string input){
        textToDisplay = input;
    }

    std::string UIObject::getText(){
        return textToDisplay;
    }

    void UIObject::mouseDown(int x, int y){

    }

    void UIObject::mouseUp(int x, int y){

    }

    void UIObject::draw(){
        
    }
}