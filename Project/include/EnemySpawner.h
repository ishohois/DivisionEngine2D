#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "GameManager.h"
#include "SystemResources.h"
#include <vector>
#include "Vector2D.h"
#include "Enemy.h"
#include "GameObject.h"
#include <random>
#include "TextureManager.h"

namespace diva
{

    class EnemySpawner : public GameObject
    {
    private:
        float startTimer = 5.0f;
        float counter;
        bool started = false;
        Vector2D *follow;
        int *hp;

    public:
        EnemySpawner();
        ~EnemySpawner() {}
        void loadEnemyWave();
        Vector2D getRandomSide();
        void setFollowPos(Vector2D *follow);
        void setHP(int *hp);
        virtual void gameObjectUpdate(float dt);
        virtual void draw() const {};
        virtual void updateCollision(){};
    };
}

#endif