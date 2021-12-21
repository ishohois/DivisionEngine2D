#include "Input.h"
#include <iostream>

namespace diva
{

    Input *Input::instance = nullptr;

    Input::Input()
    {
        currentKey = SDL_GetKeyboardState(nullptr);
    }

    void Input::handleInput()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                quitLoop = true;
                break;
            case SDL_KEYDOWN:
                keyDown();
                break;
            case SDL_KEYUP:
                keyUp();
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseDown(e.button.x, e.button.y);
                break;
            case SDL_MOUSEBUTTONUP:
                mouseUp(e.button.x, e.button.y);
                break;
            }
        }
    }

    bool Input::quit()
    {
        return quitLoop;
    }

    bool Input::getKeyDown(KEYS key)
    {
        if (currentKey[key] == 1)
        {
            return true;
        }
        return false;
    }

    void Input::keyDown()
    {
        currentKey = SDL_GetKeyboardState(nullptr);
    }

    void Input::keyUp()
    {
        currentKey = SDL_GetKeyboardState(nullptr);
    }

    bool Input::getMouseButton(MOUSEBUTTON button){
        mousePos.mouseButton = SDL_GetMouseState(&mousePos.x, &mousePos.y);
        if((mousePos.mouseButton & button) != 0){
            return true;
        }
        return false;
    }

    void Input::mouseDown(int x, int y)
    {
        mousePos.x = x;
        mousePos.y = y;
    }

    void Input::mouseUp(int x, int y)
    {
        mousePos.x = x;
        mousePos.y = y;
    }

};
