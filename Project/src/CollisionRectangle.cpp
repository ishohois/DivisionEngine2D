#include <CollisionRectangle.h>
#include <SDL2/SDL_image.h>
#include <SystemResources.h>



namespace diva
{

    CollisionRectangle::CollisionRectangle(Vector2D& objectpos, int w, int h) : GameObject(), 
    collider{objectpos, w, h, "Collision"},
    srcRect{(int)objectpos.x, (int)objectpos.y, w, h}
    {
        texture = IMG_LoadTexture(system.renderer, (resPath + "images/Block.png").c_str());
    }
    void CollisionRectangle::gameObjectUpdate(float dt) // Update i unity gameObject
    {
    }

    void CollisionRectangle::draw() const
    {
        SDL_RenderCopy(system.renderer, texture, NULL, &srcRect);
    }

    CollisionRectangle::~CollisionRectangle()
    {
        SDL_DestroyTexture(texture);
    }

};
