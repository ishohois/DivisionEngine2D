#if !defined(BACKGROUND_H)
#define BACKGROUND_H

#include "GameObject.h"
namespace diva
{

    class BackGround : public GameObject
    {
    private:
        int *hp;

    public:
        virtual void draw() const;
        virtual void gameObjectUpdate(float dt);
        BackGround(/* args */);
        void setHP(int *hp);
    };

}

#endif // BACKGROUND_H
