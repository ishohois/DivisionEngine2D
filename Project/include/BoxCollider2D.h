#ifndef BOXCOLLIDER2D_H
#define BOXCOLLIDER2D_H

#include <SDL2/SDL.h>
#include "Vector2D.h"

namespace diva
{
    class BoxCollider2D
    {
    public:
        BoxCollider2D() {}
        BoxCollider2D(Vector2D &objectPosition, int w, int h, std::string tag) : gameObjectPosition(&objectPosition),
        objectTag(tag), colliderRect{static_cast<int>(objectPosition.x), static_cast<int>(objectPosition.y), w, h}{}
        ~BoxCollider2D(){}


        inline void updateCollider()
        {
            colliderRect.x = gameObjectPosition->x;
            colliderRect.y = gameObjectPosition->y;
        };

        inline Vector2D getCenterPoint() const
        {
            float centerPointX = colliderRect.x + (colliderRect.w / 2);
            float centerPointY = colliderRect.y + (colliderRect.h / 2);
            return Vector2D(centerPointX, centerPointY);
        }
        inline const SDL_Rect &getColliderRect() const { return colliderRect; }
        inline void setObjectTag(std::string tag) { objectTag = tag; }
        inline std::string getObjectTag() const { return objectTag; }

    private:
        Vector2D *gameObjectPosition; // is used to connect to the object that has the collider instance
        std::string objectTag;
        SDL_Rect colliderRect;
    };

};

#endif
