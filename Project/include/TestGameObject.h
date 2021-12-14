#include "GameObject.h"
#include "Input.h"
#include <SDL2/SDL.h>
#include "Vector2D.h"
#include "Rigidbody2D.h"
#include "BoxCollider2D.h"

namespace diva
{

    class TestGameObject : public GameObject
    {
    private:
        SDL_Texture *texture;
        Input *input;
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        RigidBody2D rb;
        BoxCollider2D collider;
        SDL_Rect srcRect;
        SDL_Rect dstRect;

    protected:
    public:
        Vector2D position;
        TestGameObject(int x, int y, int w, int h);
        ~TestGameObject();
        virtual void draw();
        virtual void gameObjectUpdate(float dt);
        void verticalMovement();
        bool checkCollision(const SDL_Rect &, const SDL_Rect &);
        BoxCollider2D &getCollider() { return collider; };
        virtual void keyDown(SDL_Event e);
        virtual void keyUp(SDL_Event e);
    };

};