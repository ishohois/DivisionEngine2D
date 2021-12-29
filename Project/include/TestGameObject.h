#include "GameObject.h"
#include "Input.h"
#include "Vector2D.h"
#include "Rigidbody2D.h"
#include "BoxCollider2D.h"

namespace diva
{

    class TestGameObject : public GameObject
    {
    private:
        Vector2D position;
        RigidBody2D rb;
        BoxCollider2D collider;

    public:
    
        TestGameObject(int x, int y, int w, int h);
        ~TestGameObject();
        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        virtual void updateCollision(BoxCollider2D collision);
        BoxCollider2D &getCollider() { return collider; }
    };

};