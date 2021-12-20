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
        SPACE = SDL_SCANCODE_SPACE,
        FIRE1 = SDL_SCANCODE_M,
        FIRE2 = SDL_SCANCODE_N
    };

     struct MousePos
        {
            int x, y;
        };

    class Input
    {
    private:
        const Uint8 *currentKey;
        static Input *instance;
        bool quitLoop = false;
        Input();

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
        void keyDown();
        void keyUp();
        void mouseUp(int x, int y);
        void mouseDown(int x, int y);
        bool quit();

        MousePos mousePos;       
    };

    typedef Input InputHandler;
} // namespace diva

#endif