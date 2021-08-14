#ifndef GE_SPRITESHEET_HPP
#define GE_SPRITESHEET_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

namespace ge {
    namespace resource {
        class Spritesheet {
        public:
            Spritesheet(const char *path){
                IMG_Init(IMG_INIT_PNG);

                spriteSheet = IMG_Load(path);
                if(!spriteSheet){ printf("Error: reading png '%s'\nSDL_Image Error: %s", path, IMG_GetError()); }
                SDL_LockSurface(spriteSheet);

                IMG_Quit();
            }

            ~Spritesheet(){
                SDL_FreeSurface(spriteSheet);
            }

            SDL_Surface *sheet(){ return spriteSheet; }

        private:
            SDL_Surface *spriteSheet;
        };
    }
}

#endif