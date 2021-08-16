#include "selector.hpp"

namespace herbglitch {
    namespace ui {
        Selector::Selector(ge::Data *data): data(data), selection({data->mouse.x, data->mouse.y, 0, 0}), x(data->mouse.x), y(data->mouse.y){}

        void Selector::update(){
            selection.x = (x < data->mouse.x)? x : data->mouse.x;
            selection.y = (y < data->mouse.y)? y : data->mouse.y;
            selection.w = (x < data->mouse.x)? data->mouse.x - x : x - data->mouse.x;
            selection.h = (y < data->mouse.y)? data->mouse.y - y : y - data->mouse.y;
        }

        void Selector::render(){
            SDL_SetRenderDrawColor(data->renderer, 0x00, 0xff, 0x00, 0xff);
            SDL_RenderDrawRect(data->renderer, &selection);
        }

        SDL_Rect Selector::shape(){ return selection; }
    }
}