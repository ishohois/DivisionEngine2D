#include "GameObject.h"
#include "Input.h"

namespace diva
{

    class TestGameObject : public GameObject
    {
    private:
        //SDL_Texture *texture;
        Input* input;
        
        bool moveUp;
        bool moveDown;
        bool moveRight;
        bool moveLeft;

        bool isMovingXAxel;
        bool isMovingYAxel;
        bool entryState;
        
        int speed = 0;
        int setStateToHorizontal;

    public:
        TestGameObject(int x, int y, int w, int h);
        ~TestGameObject();
        virtual void draw() const;
        virtual void gameObjectUpdate();
        void verticalMovement();
        

        virtual void keyDown(SDL_Event e);
        virtual void keyUp(SDL_Event e);
    };

};