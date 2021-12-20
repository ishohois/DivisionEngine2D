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
        std::vector<GameObject *> gameObjects; //
        std::vector<GameObject *> added;       //
        std::vector<GameObject *> removed;     //
        std::vector<BoxCollider2D*> colliders; // 

        bool quit = false;
        void handleEvents();
        void updateObjects(float dt);
        void handleCollisions();
        void render();
        void delay(Uint32 nextTick);

    protected:
    public:
        void add(GameObject *gameObject);
        void remove(GameObject *gameObject);
        void runGameLoop();
        void addCollider(BoxCollider2D& b);
    };
};

#endif
