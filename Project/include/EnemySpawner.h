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
{ /* Denna klass tillhör spelet. 
    Denna klass spawner fiender sålänge spelaren har Hp.
     De spawnas alltid utanför skärmen och går in mot spelaren.

*/

    class EnemySpawner : public GameObject
    {
    private:
        float startTimer = 5.0f;
        float counter;
        bool started = false;
        Vector2D *follow;
        int *hp; // Spelarens HP

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