#include "GameManager.h"
#include "SystemResources.h"
#include "TestGameObject.h"
#include "Vector2D.h"

using namespace diva;

GameManager* g = nullptr;

int main(int argc, char *argv[])
{
    g = new GameManager();

    TestGameObject* tg = new TestGameObject(0,0,50,50);
    g->add(tg);
    g->runGameLoop();

    return 0;
}
