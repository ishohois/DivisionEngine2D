#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H
#include "GameStateManager.h"
#include <vector>

namespace diva
{

    class GameStateMachine
    {
    
    private:

    std::vector<GameStateManager*> m_gameStates;
    
    public:

    void pushState(GameStateManager* pState); // Removing one state and adding another.
    void changeState(GameStateManager* pState); // Adding one state without removing a previous state
    void popState(); // Removing one state withoyt adding another
    void update();
    void render();
    


    };

}
#endif