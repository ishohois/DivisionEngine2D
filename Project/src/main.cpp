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
  
    Player *p = new Player(640, 0, 50, 50);
    Enemy *e = new Enemy(500, 500, 50, 50);
    e->setFollowPos(p->getPosition());
    Wall *w = new Wall(Vector2D{200,500}, 50, 50);

    BackGround *b1 = new BackGround();

    g->add(b1);
    g->add(p);
    g->add(e);
    g->add(w);
    

    g->addCollider(p->getCollider());   
    g->addCollider(e->getCollider());
    g->addCollider(w->getCollider());
    g->runGameLoop();

    return 0;
}
