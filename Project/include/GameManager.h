#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameObject.h"
#include <vector>
#include <SDL2/SDL.h>
#include "BoxCollider2D.h"

namespace diva
{
    class GameManager
    {
    private:
        GameManager(){};
        static GameManager *instance;
        std::vector<GameObject *> gameObjects;  //
        std::vector<GameObject *> added;        //
        std::vector<GameObject *> removed;      //
        std::vector<BoxCollider2D *> colliders; //
        std::vector<BoxCollider2D *> addedC;
        std::vector<BoxCollider2D *> removedC;

        bool quit = false;
        void handleEvents();
        void updateObjects(float dt);
        void handleCollisions();
        void render();
        void delay(Uint32 nextTick);

    protected:
    public:
        static GameManager *getInstance()
        {
            if (!instance)
            {
                instance = new GameManager();
            }
            return instance;
        }
        void add(GameObject *gameObject);
        void remove(GameObject *gameObject);
        void addCollider(BoxCollider2D &b);
        void removeCollider(BoxCollider2D &b);
        void runGameLoop();
    };

};

#endif
