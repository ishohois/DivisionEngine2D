#include "GameObject.h"
#include "BoxCollider2D.h"
#include "Vector2D.h"

namespace diva
{
    class CollisionRectangle : public GameObject
    {
    public:
        CollisionRectangle(Vector2D &objectpos, int w, int h);
        virtual void draw();
        virtual void gameObjectUpdate(float dt);
        BoxCollider2D &getCollider() { return collider; }
        ~CollisionRectangle();

    private:
        BoxCollider2D collider;
        SDL_Rect srcRect;
        SDL_Texture *texture;
    };

};