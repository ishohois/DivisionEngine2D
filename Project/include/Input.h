#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

namespace diva
{
    enum KEYS
    {
        UP = SDL_SCANCODE_UP,
        DOWN = SDL_SCANCODE_DOWN,
        LEFT = SDL_SCANCODE_LEFT,
        RIGHT = SDL_SCANCODE_RIGHT,
        W = SDL_SCANCODE_W,
        A = SDL_SCANCODE_A,
        S = SDL_SCANCODE_S,
        D = SDL_SCANCODE_D,
        E = SDL_SCANCODE_E,
        Q = SDL_SCANCODE_Q,
        RETURN = SDL_SCANCODE_RETURN,
        SPACE = SDL_SCANCODE_SPACE,
        BACKSPACE = SDL_SCANCODE_BACKSPACE,
        M = SDL_SCANCODE_M,
        N = SDL_SCANCODE_N,
    };

    enum MOUSEBUTTON
    {
        LMB = SDL_BUTTON_LMASK,
        MMB = SDL_BUTTON_MMASK,
        RMB = SDL_BUTTON_RMASK,
    };

    struct MousePos
    {
        int x, y;
        Uint32 mouseButton;
    };

    class Input
    {
    private:
        const Uint8 *currentKey;
        static Input *instance;
        bool quitLoop = false;
        Input();
        Input(const Input &other) = delete;
        const Input &operator=(const Input &other) = delete;
        void keyDown();
        void keyUp();

    public:
        static Input *getInstance()
        {
            if (!instance)
            {
                instance = new Input();
            }
            return instance;
        }
        void handleInput();
        bool getKeyDown(KEYS key);
        bool getMouseButton(MOUSEBUTTON button);
        void mouseUp(int x, int y);
        void mouseDown(int x, int y);
        bool quit();

        MousePos mousePos;
    };

    typedef Input InputHandler;
} // namespace diva

#endif