#ifndef GE_SPRITESHEET_HPP
#define GE_SPRITESHEET_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

namespace ge {
    namespace resource {
        static SDL_Texture *spritesheet(SDL_Renderer *renderer, const char *path){
            IMG_Init(IMG_INIT_PNG);
            SDL_Surface *surface = IMG_Load(path);
            if(!surface){ printf("Error: reading png '%s'\nSDL_Image Error: %s", path, IMG_GetError()); }

            SDL_Texture *spritesheet = SDL_CreateTextureFromSurface(renderer, surface);

            SDL_FreeSurface(surface);
            IMG_Quit();

            return spritesheet;
        }
    }
}

#endif