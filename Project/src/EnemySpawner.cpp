#include "EnemySpawner.h"

namespace diva
{
    EnemySpawner::EnemySpawner()
    {
        GameManager::getInstance()->add(this);
        counter = 0.5f;
    }

    void EnemySpawner::loadEnemyWave()
    {
        if(!follow){
            return;
        }
        Vector2D side = getRandomSide();
        Enemy *e = new Enemy(side.x,side.y, 50, 50);
        if(!e){
            return;
        }
        e->setFollowPos(follow);
        GameManager::getInstance()->add(e);
        GameManager::getInstance()->addCollider(e->getCollider());
    }

    Vector2D EnemySpawner::getRandomSide()
    {
        static std::default_random_engine e;
        static std::uniform_int_distribution<> dis(1, 4);
        Vector2D side{0,0};
        switch (dis(e))
        {
        case 1:
            side = Vector2D(SCREENWIDTH / 2, 0);
            break;
        case 2:
            side =  Vector2D(SCREENWIDTH , SCREENHEIGHT / 2);
            break;
        case 3:
            side =  Vector2D(SCREENWIDTH / 2, SCREENHEIGHT);
            break;
        case 4:
            side =  Vector2D(0, SCREENHEIGHT / 2);
            break;
        }
        return side;
    }

    void EnemySpawner::setHP(int *hpP){
        hp = hpP;
    }

    void EnemySpawner::setFollowPos(Vector2D *f)
    {
        follow = f;
    }

    void EnemySpawner::gameObjectUpdate(float dt)
    {
        if(hp && *hp<= 0){
            return;
        }

        if (!started)
        {
            startTimer -= (dt / 100);
        }

        if (startTimer <= 0)
        {
            startTimer = 0.5f;
            started = true;
        }

        if (started)
        {
            counter -= (dt / 100);
            if (counter <= 0)
            {
                counter = 0.5f;
                loadEnemyWave();
            }
        }
    }

}
