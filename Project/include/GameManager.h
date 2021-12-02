#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameObject.h"
#include <vector>

class GameManager
{
private:
    std::vector<GameObject *> gameObjects; //
    std::vector<GameObject *> added;       //
    std::vector<GameObject *> removed;     //
    bool quit = false;
    void handleInput(SDL_Event &);
    void updateObjects();
    void render();
    void delay(Uint32 nextTick);

protected:
public:
    void add(GameObject *gameObject);
    void remove(GameObject *gameObject);
    void runGameLoop();
};

#endif
