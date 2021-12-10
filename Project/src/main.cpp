#include "GameManager.h"
#include "SystemResources.h"
#include "TestGameObject.h"
#include "Timer.h"

using namespace diva;

GameManager *g = nullptr;

int main(int argc, char *argv[])
{
    
    
    g = new GameManager();
    
    

    TestGameObject *tg = new TestGameObject(640, 0, 50, 80);
    g->add(tg);
    g->runGameLoop();

    return 0;
}
