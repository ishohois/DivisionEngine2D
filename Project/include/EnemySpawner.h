#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "GameManager.h"
#include "SystemResources.h"
#include <vector>
#include "Vector2D.h"
#include "Enemy.h"

namespace diva
{

    struct Wave
    {
        int numEnemy;
    };

    class EnemySpawner
    {
        private:
        std::vector<Wave> waves;
        
        public:
        EnemySpawner();
        ~EnemySpawner();
        void SpawnEnemyWave();
        void LoadEnemyWave();
    };
}

#endif