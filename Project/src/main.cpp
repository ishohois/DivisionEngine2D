#include "GameManager.h"
#include "SystemResources.h"
#include "TestGameObject.h"
#include "Timer.h"
#include "CollisionRectangle.h"
#include "Vector2D.h"
#include "BackGround.h"
#include "Wall.h"

using namespace diva;

GameManager *g = nullptr;

int main(int argc, char *argv[])
{
    Vector2D vec{200.0f, 500.0f};
    g = new GameManager();
    TestGameObject *tg = new TestGameObject(640, 0, 50, 50);
    // CollisionRectangle *cr1 = new CollisionRectangle(vec, 200, 50);
    // vec.x = 400.0f;
    // CollisionRectangle *cr2 = new CollisionRectangle(vec, 200, 50);
    // vec.x = 600.0f;
    // CollisionRectangle *cr3 = new CollisionRectangle(vec, 200, 50);

    Wall *w1 = new Wall(new Vector2D(640 * 0.75f, 150), 200, 50); // = x1, y1
    Wall *w2 = new Wall(new Vector2D(640 * 0.75f, 300), 200, 50);// = x1, y2
    Wall *w3 = new Wall(new Vector2D(380, 150), 50, 200); // || x2, y3
    Wall *w4 = new Wall(new Vector2D(740, 150), 50, 200); // || x3, y3

    BackGround *b1 = new BackGround();

    g->add(b1);
    g->add(tg);
    // g->add(cr1);
    // g->add(cr2);
    // g->add(cr3);
    g->add(w1);
    g->add(w2);
    g->add(w3);
    g->add(w4);

    g->addCollider(tg->getCollider());
    // g->addCollider(cr1->getCollider());
    // g->addCollider(cr2->getCollider());
    // g->addCollider(cr3->getCollider());
    g->addCollider(w1->getCollider());
    g->addCollider(w2->getCollider());
    g->addCollider(w3->getCollider());
    g->addCollider(w4->getCollider());

    g->runGameLoop();

    return 0;
}
