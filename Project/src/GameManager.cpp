#include "GameManager.h"
#include "SystemResources.h"
#include <iostream>
#include <Timer.h>
#include "CollisionHandler.h"
#include "Contact.h"
#include "TestGameObject.h"
#include "TextureManager.h"

namespace diva
{
    TextureManager *tMan = TextureManager::getInstance();
    /* 
RunGameloop
Kontrollera input
Kolla gameObject
    kalla på deras tick/update funktion.
        Olika beteenande t.ex rörsig.
Rendera gameObject
Kontrollera tiden och evntuellet fördröja den. FPS.
*/

    //#define FPS 60;
    Timer *Timer::instance = nullptr;
    Timer *time = Timer::getInstance();

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

    void GameManager::updateObjects(float dt)
    {
        for (auto *g : gameObjects)
        {
            g->gameObjectUpdate(dt);
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

    void GameManager::addCollider(BoxCollider2D &b)
    {
        colliders.push_back(&b);
    }

    void GameManager::handleCollisions()
    {

        Contact c;

        // for (auto b : colliders)
        // {
        //     if (CollisionHandler::collisionDetection(*player, *b, c))
        //     {
        //         player->OnCollision(b, c);
        //         b->OnCollision(p, c);
        //     }
        // }
    }

    void GameManager::render()
    {
        SDL_SetRenderDrawColor(system.renderer, 255, 255, 255, 255);
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
        std::cout << delay << std::endl;
    }

    void GameManager::runGameLoop()
    {
        while (!quit)
        {
            SDL_Event event;
            Uint32 nextTick = time->tickInterval + time->getTicks();
            // handle input
            handleInput(event);
            // update gameobject
            updateObjects(time->deltaTime(nextTick));
            handleCollisions();
            // render objects
            render();
            time->frameRateCap(nextTick);
        }
    }
};
