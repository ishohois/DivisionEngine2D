#ifndef LABEL_H
#define LABEL_H
#include "UIObject.h"
#include "SDL2/SDL.h"
#include <string>

namespace diva
{
    class Label : public UIObject{
    public:
       static Label* getInstance(int x, int y, int w, int h, std::string txt);
       void setText(std::string);
       std::string getText();
       void draw() const;
       ~Label();
       virtual void gameObjectUpdate(float dt);

       protected:
       Label(int x, int y, int w, int h, std::string txt);
       private:
        std::string text;
        SDL_Texture* texture;
    };

}

#endif
