#ifndef BUTTON_H
#define BUTTON_H
#include "UIObject.h"
#include <string>
#include "SDL2/SDL.h"

namespace diva{
    class Button : public UIObject{
        public:
        static Button* getInstance(int x, int y, int w, int h, std::string txt);
        void mouseDown(const SDL_Event&);
		void mouseUp(const SDL_Event&);
		void draw() const;
        virtual void perform(Button* source) {}
		~Button();
        virtual void gameObjectUpdate(float dt);

        protected:
		Button(int x, int y, int w, int h, std::string txt);

        private:
		std::string text;
		SDL_Texture* texture;
		bool isDown = false;
    };
}

//extern std::string resPath;
//kanske inte behövs

#endif
