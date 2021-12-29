#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "BoxCollider2D.h"
#include "Contact.h"

namespace diva
{
    struct CollisionHandler
    {
        static bool collisionDetection(const BoxCollider2D &b1, const BoxCollider2D &b2, Contact& ct);
        static bool collisionDetection(const BoxCollider2D &b1, const BoxCollider2D &b2);
        static Vector2D collisionResolution(const BoxCollider2D &b, Contact& ct);
    };
};

#endif