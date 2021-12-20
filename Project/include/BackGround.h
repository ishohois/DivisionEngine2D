#if !defined(BACKGROUND_H)
#define BACKGROUND_H

#include "GameObject.h"
namespace diva
{

    class BackGround : public GameObject
    {
    private:

    public:
        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        BackGround(/* args */);
      
    };

}

#endif // BACKGROUND_H
