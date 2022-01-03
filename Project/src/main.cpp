#include "GameManager.h"
#include "SystemResources.h"
#include "Vector2D.h"
#include "BackGround.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Wall.h"

using namespace diva;

GameManager *g = GameManager::getInstance();

/*räkna upp vilka filer som tillför spelet
- TestGameObject är vår bla bla
- Background är det där fina där bak*/
int main(int argc, char *argv[])
{

    BackGround *b1 = new BackGround();
    g->add(b1);
    
    Player *p = new Player(640, 0, 50, 50);
    Enemy *e = new Enemy(500, 500, 50, 50);
    e->setFollowPos(p->getPosition());

    Wall *w = nullptr;
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            w = new Wall(Vector2D{j * (float)(SCREENWIDTH/4 - 25), i * (float)(SCREENHEIGHT/3 -25)}, 50, 50);
            g->add(w);
            g->addCollider(w->getCollider());
        }
    }
    w = nullptr;

    g->add(p);
    g->add(e);

    g->addCollider(p->getCollider());
    g->addCollider(e->getCollider());
    g->runGameLoop();

    return 0;
}
