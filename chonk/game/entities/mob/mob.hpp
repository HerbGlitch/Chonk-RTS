#pragma once

#include "../entity.hpp"

namespace herbglitch {
    namespace entities {
        class Mob : public Entity {
        public:
            Mob(ge::Data *data, ge::resource::Spritesheet *spritesheet, SDL_Point coords, EntityType entityType);

            void update();
        };
    }
}