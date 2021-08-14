#ifndef GE_SPRITE_HPP
#define GE_SPRITE_HPP

#include <SDL2/SDL.h>

namespace ge {
    namespace resource {
        class Sprite {
        public:
            Sprite(SDL_Surface *spritesheet): spritesheet(spritesheet){}
            // SDL_RenderCopy()
        private:
            SDL_Rect bounds;
            SDL_Surface *spritesheet;
        };
    }
}

#endif