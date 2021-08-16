#include "handler.hpp"

namespace herbglitch {
    namespace entities {
        Handler::Handler(ge::Data *data, SDL_Texture *spritesheet, ui::Handler *uiHandler): data(data), uiHandler(uiHandler){
            add(new Base(data, spritesheet, SDL_Point { 600, 300 }, EntityType::BASE));
            add(new  Mob(data, spritesheet, SDL_Point { 400, 100 }, EntityType::BASIC));
            add(new  Mob(data, spritesheet, SDL_Point { 500, 070 }, EntityType::BASIC));
            add(new  Mob(data, spritesheet, SDL_Point { 600, 100 }, EntityType::BASIC));
            add(new  Mob(data, spritesheet, SDL_Point { 700, 070 }, EntityType::ADVANCED));
            add(new  Mob(data, spritesheet, SDL_Point { 800, 100 }, EntityType::ADVANCED));
        }

        Handler::~Handler(){}

        void Handler::update(){
            updateHandler<Entity>();
            checkSlect();
        }

        void Handler::checkSlect(){
            if(data->mouse[SDL_BUTTON_LEFT] != ge::Mouse::RELEASED){ return; }
            for(Entity *entity : hTypes){
                SDL_Rect selectionArea = uiHandler->getSelectedArea();
                bool contains = (bool) SDL_HasIntersection(&selectionArea, &(entity->getPos()));
                entity->setSelect(contains);
            }
        }
    }
}