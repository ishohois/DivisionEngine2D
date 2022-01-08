#include "GameManager.h"
#include "SystemResources.h"
#include "Vector2D.h"
#include "BackGround.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Wall.h"
#include "EnemySpawner.h"

using namespace diva;

GameManager *g = GameManager::getInstance();

/*
Kommentarer vad klasserna göra/tillhör finns i H-filerna.
räkna upp vilka filer som tillför spelet
- Player har funktioner för spelarens rörelse, vapen samt kollisionsdetektering.
- Wall sköter väggarnas kollision och logik.
- Bullet sköter logik för skotten som spelaren skjuter ut.
- EnemySpawner skapar fiender 
- BackGround är klassen för att lägga till en bakgrund samt sköter den text som visas.
*/
int main(int argc, char *argv[])
{

    BackGround *b1 = new BackGround();
    g->add(b1);
    
    Player *p = new Player((float)(SCREENWIDTH / 2 - 25), (float)(SCREENHEIGHT / 2 - 25), 50, 50);
    b1->setHP(p->getHP());

    EnemySpawner *spawner = new EnemySpawner();
    spawner->setFollowPos(p->getPosition());
    spawner->setHP(p->getHP());

    g->add(p);
    g->addCollider(p->getCollider());

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

    g->runGameLoop();

    p = nullptr;
    spawner = nullptr;
    w = nullptr;

    return 0;
}
