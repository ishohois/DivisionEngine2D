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
    
    Vector2D vec{600.0f, 500.0f};
    g = new GameManager();
    TestGameObject *tg = new TestGameObject(640, 0, 50, 50);
    // CollisionRectangle *cr1 = new CollisionRectangle(0,500, 200,50);
    // CollisionRectangle *cr2 = new CollisionRectangle(200,500, 200,50);
    // CollisionRectangle *cr3 = new CollisionRectangle(400,500, 200,50);
    CollisionRectangle *cr4 = new CollisionRectangle(vec, 200,50);
    // CollisionRectangle *cr5 = new CollisionRectangle(800,500, 200,50);
    // CollisionRectangle *cr6 = new CollisionRectangle(1000,500, 200,50);
    

    g->add(tg);
    // g->add(cr1);
    // g->add(cr2);
    // g->add(cr3);
    g->add(cr4);
    // g->add(cr5);
    // g->add(cr6);
    g->addCollider(tg->getCollider());
    g->addCollider(cr4->getCollider());

    g->runGameLoop();

    // till tg lägger jag till colliders som finns i världen 
    // skapa i tgs move funktion skapar jag villkor för collision
        // testa för vänster kollision
            // vänd hastighetsvektorn 
        // testa för höger kollision
            // vänd hastighetsvektorn 
        // testa för topp kollision
        // testa för botten kollision

    return 0;
}
