#ifndef GE_HPP
#define GE_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include "handler.hpp"
#include "object.hpp"
#include "input/mouse.hpp"
#include "resource/spritesheet.hpp"
#include "resource/sprite.hpp"

namespace ge {
    struct Data {
        Handler<Object> state;
        Mouse mouse;

        SDL_Window *window;
        SDL_Renderer *renderer;

        SDL_Event event;

        float scale = 8.0f;
        float dt;
    };

    template <class initState>
    inline int Run(Data *data, int width, int height, const char *title){
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            printf("Error: initializing SDL\nSDL Error: ", SDL_GetError());
            return 3;
        }

        if(SDL_CreateWindowAndRenderer(width, height, 0, &(data->window), &(data->renderer))){
            printf("Error: creating window and renderer\nSDL Error: ", SDL_GetError());
            return 3;
        }

        SDL_SetWindowTitle(data->window, title);

        data->state.add(new initState(data));

        while(true){
            SDL_PollEvent(&(data->event));
            if(data->event.type == SDL_QUIT){ break; }
            data->mouse.update(data->event);

            data->state.update();

            SDL_SetRenderDrawColor(data->renderer, 0x33, 0x48, 0x57, 0x00);
            SDL_RenderClear(data->renderer);
            data->state.render();
            SDL_RenderPresent(data->renderer);
        }

        SDL_DestroyRenderer(data->renderer);
        SDL_DestroyWindow(data->window);

        return 0;
    }
}

#endif // !GE_HPP
