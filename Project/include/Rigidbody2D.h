#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H
#include "Vector2D.h"

#define MASS 1.0f
#define GRAVITY 9.8f

namespace diva
{

    class RigidBody2D
    {

    public:
        RigidBody2D() : rbMass(MASS), rbGravity(GRAVITY) {}

        void updatePhysics(float dt)
        {
            rbAcceleration.x = (rbForce.x + rbFriction.x) / rbMass;
            rbAcceleration.y = 0.5f * (rbForce.y + rbGravity * rbGravity) / rbMass;

            rbVelocity = rbAcceleration;
            rbPosition = rbVelocity;

        }

        inline void setMass(float mass) { rbMass = mass; }
        inline void setGravity(float gravity) { rbGravity = gravity; }

        inline Vector2D getPosition(){return rbPosition;}
        inline Vector2D getVelocity(){return rbVelocity;}
        inline Vector2D getAcceleration(){return rbAcceleration;}

        // force
        inline void applyForce(Vector2D f) { rbForce = f; }
        inline void applyForceX(float fx) { rbForce.x = fx; }
        inline void applyForceY(float fy) { rbForce.y = fy; }
        inline void resetForce() { rbForce = Vector2D(0, 0); }

        // friction
        inline void applyFriction(Vector2D fr) { rbFriction = fr; }
        inline void resetFriction() { rbFriction = Vector2D(0, 0); }

        Vector2D getRbPosition()
        {
            return rbPosition;
        }

    private:
        float rbMass;
        float rbGravity;

        Vector2D rbPosition;
        Vector2D rbVelocity;
        Vector2D rbForce;
        Vector2D rbFriction;
        Vector2D rbAcceleration;
    };

}
#endif