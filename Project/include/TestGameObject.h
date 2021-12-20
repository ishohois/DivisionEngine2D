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
      //  SDL_Texture *texture;
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Vector2D position;
        RigidBody2D rb;
        BoxCollider2D collider;
        const Uint8* currentKey;
    protected:
    public:
        TestGameObject(int x, int y, int w, int h);
        ~TestGameObject();
        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        void verticalMovement();
        virtual void updateCollision(BoxCollider2D collision);
        BoxCollider2D &getCollider() { return collider; };
    };

};