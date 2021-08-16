#include "mob.hpp"

namespace herbglitch {
    namespace entities {
        Mob::Mob(ge::Data *data, ge::resource::Spritesheet *spritesheet, SDL_Point coords, EntityType entityType): Entity(data, entityType){
            switch(entityType){
                case EntityType::BASIC:
                    sprite = new ge::resource::Sprite(spritesheet->sheet(), TEMP_BASIC, coords);
                    break;

                default:
                    sprite = new ge::resource::Sprite(spritesheet->sheet(), TEMP_ADVANCED, coords);
                    break;
            }
        }


        void Mob::update(){

        }
    }
}