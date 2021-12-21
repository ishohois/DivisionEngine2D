#include "GameManager.h"
#include "SystemResources.h"
#include "TestGameObject.h"
#include "Timer.h"
#include "CollisionRectangle.h"
#include "Vector2D.h"

using namespace diva;

GameManager *g = nullptr;

int main(int argc, char *argv[])
{
    Vector2D vec{200.0f, 500.0f};
    g = new GameManager();
    TestGameObject *tg = new TestGameObject(640, 0, 50, 50);
    CollisionRectangle *cr1 = new CollisionRectangle(vec, 200, 50);
    vec.x = 400.0f;
    CollisionRectangle *cr2 = new CollisionRectangle(vec, 200, 50);
    vec.x = 600.0f;
    CollisionRectangle *cr3 = new CollisionRectangle(vec, 200, 50);

    g->add(tg);
    g->add(cr1);
    g->add(cr2);
    g->add(cr3);

    g->addCollider(tg->getCollider());
    g->addCollider(cr1->getCollider());
    g->addCollider(cr2->getCollider());
    g->addCollider(cr3->getCollider());

    g->runGameLoop();

    return 0;
}
