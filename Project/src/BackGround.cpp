#include "BackGround.h"
#include "TextureManager.h"
#include "SystemResources.h"

namespace diva
{
    BackGround::BackGround()
    {
        TextureManager::getInstance()->loadFont("F1", ("Fonts/Southmore.ttf"), "Hello Friends");
        // TextureManager::getInstance()->load((resPath + "images/B1.png").c_str(), "B1", system.renderer);
    }
    void BackGround::draw() const
    {
        TextureManager::getInstance()->drawText("F1", 10, 10, 400, 100);

        // TextureManager::getInstance()->draw("B1",0,0,1024,680,system.renderer);
        // SDL_Color c = {0,0,0,255};
        // TextureManager::getInstance()->drawText("F1","Hello",c,system.renderer);
    }

    void BackGround::gameObjectUpdate(float dt)
    {

        for (int i = 0; i < 10; i++)
        {

            TextureManager::getInstance()->setText("jag");
        }
    }
};
