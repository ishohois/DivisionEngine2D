#if !defined(BACKGROUND_H)
#define BACKGROUND_H

#include "GameObject.h"
namespace diva
{ /* Denna klass tillhör spelet 
    Klassen gör så att det finns en bakgrund och skriver också upp en text om spelaren är död.
*/

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
