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
        /*Denna klass är vad som håller koll på vad som finns i spelet. Om man vill lägga till någonting måste man använda denna. Den är gjord till en singelton
        för att vi vill ändas att en instance av en gamemanger ska finnas. Det gör också det betydligt lättare att skapa och lägga till objekt i klasser utanför
        main. Vilket man ofta behöver göra. Man lägger till både boxcolliders och gameobjects i olika vectorer. 
        */
    private:
        GameManager(){};
        static GameManager *instance;
        std::vector<GameObject *> gameObjects; 
        std::vector<GameObject *> added;       
        std::vector<GameObject *> removed;      
        std::vector<BoxCollider2D *> colliders; 
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
        void clean();
    };

};

#endif
