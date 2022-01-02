#include <TextureManager.h>
#include <SDL2/SDL_image.h>
#include "SystemResources.h"
namespace diva
{
    TextureManager *TextureManager::instance = nullptr; // inizilasing the instance.

    bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *TRenderer)
    {
        if (TTexturemap[id])
        {
            return true;
        }
        SDL_Surface *TTempsurface = IMG_Load(fileName.c_str()); // Loading in the texture to a surface using the file name from the function call.
        // checking if we could load in the file.
        if (TTempsurface == 0)
        {
            std::cout << "File not loaded in to the surface. FilePath incorrect?" << std::endl;
            return false;
        }
        // creates the textrure from the surface and puts it in a render context.

        SDL_Texture *TTexture = SDL_CreateTextureFromSurface(TRenderer, TTempsurface);
        // freeing up the surface cause it's no loger needed.
        SDL_FreeSurface(TTempsurface);

        if (TTexture == 0)
        {
            std::cout << "Something went wrong we are not supose to be here " << std::endl;
            return false;
        }

        // If everythiing loaded, add the texture to the map, using the texture ID as a key.
        TTexturemap[id] = TTexture;
        return true;
    }

    bool TextureManager::loadFont(std::string id, std::string fileName, std::string text)
    {
        ids = id;
        ourFont = TTF_OpenFont((resPath + fileName).c_str(), 32);

        surfaceText = TTF_RenderText_Solid(ourFont, text.c_str(), {50, 50, 50});
        T = SDL_CreateTextureFromSurface(system.renderer, surfaceText);

        SDL_FreeSurface(surfaceText);
        TTexturemap[ids] = T;
        return ourFont != nullptr;
    }

    void TextureManager::setText(const std::string &newText, std::string id)
    {

        surfaceText = TTF_RenderText_Solid(ourFont, newText.c_str(), {50, 50, 50});
        T = SDL_CreateTextureFromSurface(system.renderer, surfaceText);

        SDL_FreeSurface(surfaceText);
        TTexturemap[id] = T;
    }

    void TextureManager::drawText(std::string id, int x, int y, int w, int h)
    {
        SDL_Rect rectangel{x, y, w, h};
        SDL_RenderCopy(system.renderer, TTexturemap[id], NULL, &rectangel);
    }

    // a fucntion to draw the texture on the screen.
    void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *TRenderer, double angel, Spriteflip spriteflip)
    {

        SDL_RendererFlip flip = SDL_FLIP_NONE;

        switch (spriteflip)
        {
        case FLIPNONE:
            break;
        case HORIZONTALFLIP:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case VERTICALFLIP:
            flip = SDL_FLIP_VERTICAL;
            break;
        }

        // The srcRect copys the part of the image we want to from the texture to the screen. We use it to set the pos of the texture(sprite)
        // and we alos use it to define the width and height of the pcitre to display.
        SDL_Rect srcRect;
        // we use destRect to set the new pos of the srcRect.
        SDL_Rect destRect;

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(TRenderer, TTexturemap[id], &srcRect, &destRect, angel, 0, flip);
    }

    // In this function we us the currentFrame andcurrentRow Variables to get the appropriate frame och the animation in the source rectangle.
    void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *TRenderer,
                                   double angel, Spriteflip spriteflip)
    {
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        switch (spriteflip)
        {
        case FLIPNONE:
            break;
        case HORIZONTALFLIP:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case VERTICALFLIP:
            flip = SDL_FLIP_VERTICAL;
            break;
        }

        SDL_Rect srcRect;
        SDL_Rect destRect;
        // here we use the current frame to determent what part of the spritesheet to display.
        srcRect.x = width * currentFrame;

        srcRect.y = height * (currentRow - 1);
        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(TRenderer, TTexturemap[id], &srcRect, &destRect, angel, 0, flip);
    }

}