#include "BackGround.h"
#include "TextureManager.h"
#include "SystemResources.h"

namespace diva
{
    BackGround::BackGround()
    {

        TextureManager::getInstance()->load((resPath + "images/light_sand_template.jpg").c_str(), "B1", system.renderer);
        TextureManager::getInstance()->loadFont("F1", ("Fonts/Southmore.ttf"), "GAME OVER!");
    }
    void BackGround::draw() const
    {
        TextureManager::getInstance()->draw("B1", 0, 0, 1280, 720, system.renderer, 0, Spriteflip::FLIPNONE);
        

        if (hp && *hp <= 0)
        {
            TextureManager::getInstance()->drawText("F1", SCREENWIDTH / 2, SCREENHEIGHT -200, 400, 200);
        }
    }

    void BackGround::setHP(int *playerHP)
    {
        hp = playerHP;
    }

    void BackGround::gameObjectUpdate(float dt)
    {
    }
};
