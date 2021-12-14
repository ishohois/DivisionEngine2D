#include "GameStateMachine.h"
namespace diva
{

    void GameStateMachine::pushState(GameStateManager *pState)
    {
        m_gameStates.push_back(pState);
        m_gameStates.back()->onEnter();
    }

    void GameStateMachine::popState()
    {
        if (!m_gameStates.empty())
        {
            if (m_gameStates.back()->onExit())
            {
                delete m_gameStates.back();
                m_gameStates.pop_back();
            }
        }
    }

    void GameStateMachine::changeState(GameStateManager *pState)
    {
        if (!m_gameStates.empty())
        {
            if (m_gameStates.back()->getStateID() == pState->getStateID())
            {
                return; // doNothing
            }

            if (m_gameStates.back()->onExit())
            {
                delete m_gameStates.back();
                m_gameStates.pop_back();
            }
        }
        // push back our new state
        m_gameStates.push_back(pState);
        //initialise it
        m_gameStates.back()->onEnter();
    }
    /*
    The two follwoing function simply cheak if there are any states and if so they update and render the current state
    Whne we have designed the FSM we always use the state thats last. 
    */

    void GameStateMachine::update()
    {
        if (!m_gameStates.empty())
        {
            m_gameStates.back()->update();
        }
    }

    void GameStateMachine::render()
    {
        if (!m_gameStates.empty())
        {
            m_gameStates.back()->render();
        }
    }

}