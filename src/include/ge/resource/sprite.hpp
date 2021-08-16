#ifndef GE_SPRITE_HPP
#define GE_SPRITE_HPP

#include <SDL2/SDL.h>

namespace ge {
    namespace resource {
        class Sprite {
        public:
            Sprite(SDL_Texture *spritesheet, int xBound, int yBound, int wBound, int hBound, int xPos, int yPos): spritesheet(spritesheet), bounds(SDL_Rect {xBound, yBound, wBound, hBound}), pos(SDL_Rect {xPos, yPos, wBound, hBound}), x((float)xPos), y((float)yPos){}
            Sprite(SDL_Texture *spritesheet, SDL_Rect bounds, int xPos, int yPos): spritesheet(spritesheet), bounds(bounds), pos(SDL_Rect {xPos, yPos, bounds.w, bounds.h}), x((float)xPos), y((float)yPos){}
            Sprite(SDL_Texture *spritesheet, SDL_Rect bounds, SDL_Point pos): spritesheet(spritesheet), bounds(bounds), pos(SDL_Rect {pos.x, pos.y, bounds.w, bounds.h}), x((float)pos.x), y((float)pos.y){}

            void move(float x, float y){ this->x += x; this->y += y; pos.x = (int)this->x; pos.y = (int)this->y; }
            void move(int x, int y){ pos.x += x; pos.y += y; this->x = (float)pos.x; this->y = (float)pos.y; }
            void move(SDL_FPoint pos){ x += pos.x; y = pos.y; this->pos.x = (int)x; this->pos.y = (int)y; }
            void move(SDL_Point pos){ this->pos.x += pos.x; this->pos.y += pos.y; x = (float)this->pos.x; y = (float)this->pos.y; }

            void draw(SDL_Renderer *renderer){ SDL_RenderCopy(renderer, spritesheet, &bounds, &pos); }

            void setPos(float x, float y){ pos.x = (int)x; pos.y = (int)y; this->x = x; this->y = y; }
            void setPos(int x, int y){ pos.x = x; pos.y = y; this->x = (float)x; this->y = (float)y; }
            void setPos(SDL_FPoint pos){ this->pos.x = (int)pos.x; this->pos.y = (int)pos.y; x = pos.x; y = pos.y; }
            void setPos(SDL_Point pos){ this->pos.x = pos.x; this->pos.y = pos.y; x = (float)pos.x; y = (float)pos.y; }

            void setBounds(int x, int y, int w, int h){ bounds = {x, y, w, h}; }
            void setBounds(SDL_Rect bounds){ this->bounds = bounds; }
            void setBounds(int x, int y){bounds.x = x; bounds.y = y; }
            void setBounds(SDL_Point pos){bounds.x = pos.x; bounds.y = pos.y; }

            SDL_Rect &getPos(){ return pos; }

        private:
            SDL_Rect pos;
            SDL_Rect bounds;
            SDL_Texture *spritesheet;

            float x, y;
        };
    }
}

#endif