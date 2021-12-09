#include "GameObject.h"
#include "Input.h"
#include <SDL2/SDL.h>
#include "Vector2D.h"

namespace diva
{

    class TestGameObject : public GameObject
    {
    private:
        SDL_Texture *texture;
        Input *input;
        Vector2D position;
        SDL_RendererFlip flip = SDL_FLIP_NONE;

    protected:
        SDL_Rect srcRect;
        SDL_Rect dstRect;

    public:
        TestGameObject(int x, int y, int w, int h);
        ~TestGameObject();
        virtual void draw();
        virtual void gameObjectUpdate();
        void verticalMovement();

        virtual void keyDown(SDL_Event e);
        virtual void keyUp(SDL_Event e);
    };

};