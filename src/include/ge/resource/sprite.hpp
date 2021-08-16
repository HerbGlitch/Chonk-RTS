#ifndef GE_SPRITE_HPP
#define GE_SPRITE_HPP

#include <SDL2/SDL.h>

namespace ge {
    namespace resource {
        class Sprite {
        public:
            Sprite(SDL_Texture *spritesheet, int xBound, int yBound, int wBound, int hBound, int xPos, int yPos): spritesheet(spritesheet), bounds(SDL_Rect {xBound, yBound, wBound, hBound}), pos(SDL_Rect {xPos, yPos, wBound, hBound}){}
            Sprite(SDL_Texture *spritesheet, SDL_Rect bounds, int xPos, int yPos): spritesheet(spritesheet), bounds(bounds), pos(SDL_Rect {xPos, yPos, bounds.w, bounds.h}){}
            Sprite(SDL_Texture *spritesheet, SDL_Rect bounds, SDL_Point pos): spritesheet(spritesheet), bounds(bounds), pos(SDL_Rect {pos.x, pos.y, bounds.w, bounds.h}){}

            void move(int x, int y){ pos.x += x; pos.y += y; }
            void move(SDL_Point pos){ this->pos.x += pos.x; this->pos.y += pos.y; }

            void draw(SDL_Renderer *renderer){ SDL_RenderCopy(renderer, spritesheet, &bounds, &pos); }

            void setPos(int x, int y){ pos.x = x; pos.y = y; }
            void setPos(SDL_Point pos){ this->pos.x = pos.x; this->pos.y = pos.y; }

            void setBounds(int x, int y, int w, int h){ bounds = {x, y, w, h}; }
            void setBounds(SDL_Rect bounds){ this->bounds = bounds; }
            void setBounds(int x, int y){bounds.x = x; bounds.y = y; }
            void setBounds(SDL_Point pos){bounds.x = pos.x; bounds.y = pos.y; }

            SDL_Rect &getBounds(){ return bounds; }

        private:
            SDL_Rect pos;
            SDL_Rect bounds;
            SDL_Texture *spritesheet;
        };
    }
}

#endif