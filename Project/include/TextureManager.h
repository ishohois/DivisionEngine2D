#ifndef TEXTUREMANGER_H
#define TEXTUREMANGER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <map>

namespace diva
{
    enum Spriteflip
    {
        FLIPNONE,
        HORIZONTALFLIP,
        VERTICALFLIP
    };
    /*Den här klassen tillhör Spelmotorn

        Klassen implementerar en singelton för att vi kommer bara vilja ha en instance av denna som används itaget.
        Klassen används för att ladda in och rita ut våra objekt till skärmen. Den använder objects position,höjd och bredd för att
        bestämma positionen på skärmen.

        Load funktionen tar en filesökväf och en tag. Vi behöver en Tag för att veta vilken textur som ska laddas från MAPen av 
        texturer vi har. 
        Med funktionen drawFrame kan vi göra simpla animationer från ett sprite sheet.
     */

    class TextureManager
    {
    private:
        // Implementing a Singelton.
        TextureManager()
        {
            TTF_Init(); // CleanUpMemory
        };
        static TextureManager *instance; // A pointer to a static instance.
        TTF_Font *ourFont;
        SDL_Surface *surfaceText;
        SDL_Texture *T;
        std::string ids;

        // This map will contain all the textures in the game.
        std::map<std::string, SDL_Texture *> TTexturemap;
        std::map<std::string, TTF_Font *> TFontmap;

    public:
        static TextureManager *getInstance()
        { // this is how we accses an instance.
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
                  SDL_Renderer *TRenderer, double angel, Spriteflip spriteflip); // Takes ID and pos where we want to draw the texture, the W&H of the image
                                                                                 // It also takes the renderer we want to copy to. And also tells how we want to flip the images from start, and from start we dont
                                                                                 // want to do anything so we set flip to none.
        // Draw Frame;
        void drawFrame(std::string id, int x, int y, int widht, int height, int currentRow, int currentFrame,
                       SDL_Renderer *TRenderer, double angel, Spriteflip spriteflip); // dose the same as draw but adds a chceck
                                                                                      // what row we are on in the image spredsheet and also what frame we are in at the moment.
        bool loadFont(std::string id, std::string fileName, std::string text);
        void drawText(std::string id, int x, int y, int w, int h);
        void setText(const std::string &newText, std::string id);
        void cleanUp();
    };

}

#endif