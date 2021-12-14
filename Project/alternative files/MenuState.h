#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "GameStateManager.h"
namespace diva
{
    class MenuState : public GameStateManager
    {
    private:
    
        static const std::string s_menuId;
        /* data */
    public:

        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const {return s_menuId ;}
    
    
    };
    
    
} // namespace diva


#endif