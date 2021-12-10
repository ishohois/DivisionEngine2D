#include "GameManager.h"
#include "SystemResources.h"
#include "TextureManager.h"

namespace diva
{

    /* 
RunGameloop
Kontrollera input
Kolla gameObject
    kalla på deras tick/update funktion.
        Olika beteenande t.ex rörsig.
Rendera gameObject
Kontrollera tiden och evntuellet fördröja den. FPS.
*/

#define FPS 60;
     
    TextureManager *tMan = TextureManager::getInstance();

    void GameManager::add(GameObject *gameObject)
    {
        added.push_back(gameObject);
    }

    void GameManager::remove(GameObject *gameObject)
    {
        removed.push_back(gameObject);
    }

    void GameManager::handleInput(SDL_Event &e)
    {
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                for (auto *g : gameObjects)
                {
                    g->mouseDown(e.button.x, e.button.y);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                for (auto *g : gameObjects)
                {
                    g->mouseUp(e.button.x, e.button.y);
                }
                break;
            case SDL_KEYDOWN:
                for (auto *g : gameObjects)
                {
                    g->keyDown(e);
                }
                break;
            case SDL_KEYUP:
                for (auto *g : gameObjects)
                {
                    g->keyUp(e);
                }
                break;
            }
        }
    }

    void GameManager::updateObjects()
    {

        for (auto *g : gameObjects)
        {
            g->gameObjectUpdate();
        }

        for (auto *g : added)
        {
            gameObjects.push_back(g);
        }
        added.clear();

        for (auto *g : removed)
        {
            for (std::vector<GameObject *>::iterator it = gameObjects.begin(); it != gameObjects.end();)
            {
                if (*it == g)
                {
                    it = gameObjects.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }

        removed.clear();
    }

    void GameManager::render()
    {
        SDL_SetRenderDrawColor(system.renderer, 255, 255, 255, 0);
        SDL_RenderClear(system.renderer);
        for (auto *g : gameObjects)
        {
            g->draw(); 
            
            
        }
        SDL_RenderPresent(system.renderer);
    }

    void GameManager::delay(Uint32 nextTick)
    {
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0)
        {
            SDL_Delay(delay);
        }
    }


    void GameManager::runGameLoop()
    {
        Uint32 tickInterval = 1000 / FPS; // milliseconds per frame
        while (!quit)
        {
            SDL_Event event;
            Uint32 nextTick = tickInterval + SDL_GetTicks();
      
            // handle input
            handleInput(event);
      
            // update gameobject
            updateObjects();
      
            // render objects
            render();
            delay(nextTick);
        }
    }
};
