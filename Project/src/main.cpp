#include "GameManager.h"
#include "SystemResources.h"
#include "TestGameObject.h"

using namespace diva;


int main(int argc, char *argv[])
{
    GameManager g;
    TestGameObject* tgo = new TestGameObject(0,0,50,50); 
    g.add(tgo);
    g.runGameLoop();
    return 0;
}
