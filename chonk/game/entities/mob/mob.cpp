#include "mob.hpp"

namespace herbglitch {
    namespace entities {
        Mob::Mob(ge::Data *data, SDL_Texture *spritesheet, SDL_Point coords, EntityType entityType): Entity(data, entityType){
            switch(entityType){
                case EntityType::BASIC:
                    sprite = new ge::resource::Sprite(spritesheet, TEMP_BASIC, coords);
                    break;

                default:
                    sprite = new ge::resource::Sprite(spritesheet, TEMP_BASIC, coords);
                    break;
            }
        }


        void Mob::update(){
            if(select == selected){ return; }
            if(select){
                sprite->setBounds(TEMP_ADVANCED);
                selected = select;
            }
            if(!select){
                sprite->setBounds(TEMP_BASIC);
                selected = select;
            }
        }
    }
}