#include "handler.hpp"

namespace herbglitch {
    namespace ui {
        Handler::Handler(ge::Data *data): data(data), selector(nullptr){}
        Handler::~Handler(){ if(selector){ delete selector; } }

        void Handler::update(){
            updateSelector();
        }

        void Handler::render(){
            if(selector){ selector->render(); }
        }


        void Handler::updateSelector(){
            if(!selector){
                if(data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){ selector = new Selector(data); }
                return;
            }

            if(data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){
                selector->update();
                return;
            }

            if(data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::RELEASED){
                selectedArea = selector->shape();
                delete selector;
                selector = nullptr;
            }
        }
    }
}