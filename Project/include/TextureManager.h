#ifndef TEXTUREMANGER_H
#define TEXTUREMANGER_H
#include <SDL2/SDL.h>
#include <iostream>
#include <map>
namespace diva
{

    class TextureManager
    {
    private:
        /* data */
    public:
        bool load(std::string fileName, std::string id, SDL_Renderer *TRenderer);
        //Draw
        void draw(std::string id, int x, int y, int width, int height,
                  SDL_Renderer *TRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE); // Takes ID and pos where we want to draw the texture, the W&H of the image
                                                                                   // It also takes the renderer we want to copy to. And also tells how we want to flip the images from start, and from start we dont
                                                                                   // want to do anything so we set flip to none.
        // Draw Frame;
        void drawFrame(std::string id, int x, int y, int widht, int height, int currentRow, int currentFrame,
                       SDL_Renderer *TRenderer, SDL_RendererFlip = SDL_FLIP_NONE); // dose the same as draw but adds a chceck
                                                                                   // what row we are on in the image spredsheet and also what frame we are in at the moment.

        std::map<std::string, SDL_Texture*> TTexturemap;

    };

}

#endif