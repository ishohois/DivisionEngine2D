#ifndef TEXTUREMANGER_H
#define TEXTUREMANGER_H
#include <SDL2/SDL.h>
#include <iostream>
#include <map>
namespace diva
{

    /*What does this class do?
        This class implements a design pattern "sigelton" the reson behinde this is that we only 
        want one instance of this class to be used at anytime.
    
        This class is used for load/drawing out our differnet objects to the screen. It uses pos of the object and alos it's 
        with and height to determent it's pos on the screen.

        The load function takes a filepath and gives each object to draw an ID. We want this becuase it's 
        a way to know what item we want to work with and we can use the ID to find the pos in the map that we use to
        store all the textures. In the drawFrame function we alos take in a row and a frame 
        this eneble us to do simple animation from sprtiessheets. More infromation on what they do in this class CPP.
        
     */

    class TextureManager
    {
    private:
        // Implementing a Singelton.
        TextureManager() = default;
        static TextureManager *instance; // A pointer to a static instance.
    public:
        static TextureManager *getInstance()
        {   // this is how we accses an instance.
            // If there are no instance then we create one else we just retern the one that exist.
            if (!instance)
            {
                instance = new TextureManager();
            }
            return instance;
        }

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
        // This map will contain all the textures in the game.
        std::map<std::string, SDL_Texture *> TTexturemap;
    };

}

#endif