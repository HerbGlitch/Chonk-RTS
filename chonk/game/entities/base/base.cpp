#include "base.hpp"

namespace herbglitch {
    namespace entities {
        Base::Base(ge::Data *data, SDL_Texture *spritesheet, SDL_Point coords, EntityType entityType): Entity(data, entityType), selected(false){
            switch(entityType){
                case EntityType::BASE:
                    sprite = new ge::resource::Sprite(spritesheet, TEMP_BUILDING, coords);
                    break;

                default:
                    sprite = new ge::resource::Sprite(spritesheet, TEMP_BUILDING, coords);
                    break;
            }
        }

        void Base::update(){
            if(select == selected){ return; }
            if(select){
                sprite->setBounds(TEMP_BUILDING_SELECTED);
                selected = select;
            }
            if(!select){
                sprite->setBounds(TEMP_BUILDING);
                selected = select;
            }
        }
    }
}