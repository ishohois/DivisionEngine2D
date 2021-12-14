#include "MenuState.h"
#include <iostream>
namespace diva

{

    const std::string MenuState::s_menuId = "MENU";

    void MenuState::update()
    {
        //Nothing for now
    }

    void MenuState::render()
    {
        // nothing for now
    }

    bool MenuState::onEnter()
    {
        std::cout << "entering menustate \n";
        return true;
    }

    bool MenuState::onExit()
    {
        std::cout << "Exiting MenuState\n";
        return true;
    }

    

} // namespace diva
