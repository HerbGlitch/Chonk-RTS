#pragma once

#include <SDL2/SDL.h>

namespace ge {
    class Mouse {
    public:
        enum State { NONE, PRESSED, RELEASED };

        void update(SDL_Event &event){
            x = event.button.x;
            y = event.button.y;

            for(int i = 0; i < 5; i++){
                if((event.button.state == SDL_PRESSED || event.motion.state == SDL_PRESSED) && event.button.button == (i + 1)){
                    mouse[i] = PRESSED;
                    continue;
                }

                if(mouse[i] == PRESSED && event.button.state == SDL_RELEASED && event.button.button == (i + 1)){
                    mouse[i] = RELEASED;
                    continue;
                }

                if(mouse[i] == RELEASED){
                    mouse[i] = NONE;
                }
            }
        }

        State &operator[](int i){ return mouse[i - 1]; }

        Sint32 x, y;

    private:
        State mouse[5];
    };
}
