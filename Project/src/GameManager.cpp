#include "GameManager.h"
#include "SystemResources.h"
#include <iostream>
#include <Timer.h>
#include "CollisionHandler.h"
#include "Contact.h"
#include "TextureManager.h"
#include "Input.h"

//används för att lägga till, ta bort och hantera GameObjects(spelaren, väggar, fiender).

namespace diva
{
    GameManager *GameManager::instance = nullptr;
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

    void GameManager::handleEvents()
    {
        InputHandler::getInstance()->handleInput();
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
            g->~GameObject();
        }
        removed.clear();
    }

    void GameManager::addCollider(BoxCollider2D &b)
    {
        colliders.push_back(&b);
    }

    void GameManager::removeCollider(BoxCollider2D &b)
    {
        removedC.push_back(&b);
    }

    void GameManager::handleCollisions()
    {
        for (auto b : colliders)
        {
            for (auto g : gameObjects)
            {
                g->updateCollision(*b);
            }
        }

        for (auto b : addedC)
        {
            colliders.push_back(b);
        }
        addedC.clear();

        for (auto *b : removedC)
        {
            for (std::vector<BoxCollider2D *>::iterator it = colliders.begin(); it != colliders.end();)
            {
                if (*it == b)
                {
                    it = colliders.erase(it);
                }
                else
                {
                    it++;
                }
            }
            b->~BoxCollider2D();
        }
        removed.clear();
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
        while (!InputHandler::getInstance()->quit())
        {
            Uint32 nextTick = time->tickInterval + time->getTicks();
            // handle input
            handleEvents();
            // update gameobject
            updateObjects(time->deltaTime(nextTick));
            handleCollisions();
            // render objects
            render();
            time->frameRateCap(nextTick);
        }

        clean();
    }

    void GameManager::clean()
    {
        for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
        {
            gameObjects.erase(it);
        }

        for (auto it = colliders.begin(); it != colliders.end(); it++)
        {
            colliders.erase(it);
        }

        TextureManager::getInstance()->cleanUp();

        std::cout << "All resources released and memory have been cleaned." << std::endl;
    }
};
