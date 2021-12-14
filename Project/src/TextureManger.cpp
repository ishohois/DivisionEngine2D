#include <TextureManager.h>
#include <SDL2/SDL_image.h>
namespace diva
{
    TextureManager *TextureManager::instance = nullptr;
    // When we call this funtion we have a texture that can be used by accessing it form it's ID.
    // Useing this in draw;
    bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *TRenderer)
    {
        SDL_Surface *TTempsurface = IMG_Load(fileName.c_str());

        if (TTempsurface == 0)
        {
            return false;
        }

        SDL_Texture *TTexture = SDL_CreateTextureFromSurface(TRenderer, TTempsurface);
        SDL_FreeSurface(TTempsurface);

        if (TTexture == 0)
        {
            std::cout << "Something went wrong we are not supose to be here " << std::endl;
            return false;
        }

        // If everythiing loaded, add the texture to the list
        TTexturemap[id] = TTexture;
        return true;
    }

    void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *TRenderer, SDL_RendererFlip flip)
    {
        SDL_Rect srcRect;
        SDL_Rect destRect;

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(TRenderer, TTexturemap[id], &srcRect, &destRect, 0, 0, flip);
    }

    // In this function we us the currentFrame andcurrentRow Variables to get the appropriate frame och the animation in the source rectangle.
    void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *TRenderer, SDL_RendererFlip flip)
    {

        SDL_Rect srcRect;
        SDL_Rect destRect;

        srcRect.x = width * currentFrame;
        srcRect.y = height * (currentRow - 1);
        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;

        SDL_RenderCopyEx(TRenderer, TTexturemap[id], &srcRect, &destRect, 0, 0, flip);
    }

}