#pragma once

#include "../entity.hpp"

namespace herbglitch {
    namespace entities {
        class Mob : public Entity {
        public:
            Mob(ge::Data *data, SDL_Texture *spritesheet, SDL_Point coords, EntityType entityType);

            void update();

        private:
            bool selected;
        };
    }
}