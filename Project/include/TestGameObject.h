#include "GameObject.h"

namespace diva
{

    class TestGameObject : public GameObject
    {
    private:
        SDL_Texture *texture;
        bool moveUp;
        bool moveDown;
        bool moveRight;
        bool moveLeft;

    public:
        TestGameObject(int x, int y, int w, int h);
        ~TestGameObject();
        virtual void draw() const;
        virtual void gameObjectUpdate();
        virtual void keyDown(SDL_Event e);
        virtual void keyUp(SDL_Event e);
    };

};