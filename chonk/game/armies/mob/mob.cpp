#include "mob.hpp"

namespace herbglitch {
    namespace armies {
        Mob::Mob(ge::Data *data, SDL_Rect coords, MobType mobType, unsigned int id): ge::Object(data, id), mobType(mobType) {
        }

        Mob::~Mob(){}

        void Mob::update(){

        }

        void Mob::render(){

        }
    }
}