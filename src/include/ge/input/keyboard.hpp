#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>

namespace ge {
    class Keyboard {
    public:
        void update(SDL_Event &event){
            printf("%d\n", (int) event.key.keysym.sym);
            

            // for(int i = 0; i < 5; i++){
            //     if((event.button.state == SDL_PRESSED || event.motion.state == SDL_PRESSED) && event.button.button == (i + 1)){
            //         mouse[i] = PRESSED;
            //         continue;
            //     }

            //     if(mouse[i] == PRESSED && event.button.state == SDL_RELEASED && event.button.button == (i + 1)){
            //         mouse[i] = RELEASED;
            //         continue;
            //     }

            //     if(mouse[i] == RELEASED){
            //         mouse[i] = NONE;
            //     }
            // }
        }


    private:
    };
}

// const Uint8 *state = SDL_GetKeyboardState(nullptr);
// printf("Mouse button: %d %d %d\n", SDL_GetMouseState(nullptr, nullptr), state[SDL_SCANCODE_1], SDL_GetModState());

