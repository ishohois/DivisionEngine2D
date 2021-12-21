#include "CollisionHandler.h"
namespace diva
{

    bool CollisionHandler::collisionDetection(const BoxCollider2D &b1, const BoxCollider2D &b2, Contact &ct)
    {
        return SDL_IntersectRect(&b1.getColliderRect(), &b2.getColliderRect(), &ct.intersectRect);
    }

    Vector2D CollisionHandler::collisionResolution(const BoxCollider2D &b, Contact &ct)
    {
        Vector2D v;

        float distX = b.getCenterPoint().x - ct.getCenterPoints().x; // gives distance between two center point on x axis
        float distY = b.getCenterPoint().y - ct.getCenterPoints().y; // gives distance between two center point on y axis
        // if distX is negative intersection is on left side of b
        // if distY is negative intersection is on bottom of b
        if (fabs(distX) > fabs(distY)) // absolute values used for distance comparison if centerpoint hasn't changed it will only resolve on the side where it is changing
        {
            return Vector2D(distX > 0 ? ct.intersectRect.w : -ct.intersectRect.w, 0); // this resolves the intersection on x-axis
        }
        else
        {
            return Vector2D(0, distY > 0 ? ct.intersectRect.h : -ct.intersectRect.h); // this resolved the intersection on y-axis
        }
    }
};
