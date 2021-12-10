#include "GameObject.h"
#include <SDL2/SDL_image.h>
#include <SystemResources.h>

namespace diva
{
    class CollisionRectangle : public GameObject
    {
    public:
        CollisionRectangle(int x, int y, int w, int h) : GameObject(), srcRect{x, y, w, h}{
            texture = IMG_LoadTexture(system.renderer, (resPath + "images/Dude.png").c_str());
        }

        ~CollisionRectangle(){
            delete texture;
        }

    private:
        SDL_Rect srcRect;
        SDL_Texture* texture;
    };

};
