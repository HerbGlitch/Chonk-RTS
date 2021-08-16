#pragma once

#include "../entity.hpp"

namespace herbglitch {
    namespace entities {
        class Base : public Entity {
        public:
            Base(ge::Data *data, SDL_Texture *spritesheet, SDL_Point coords, EntityType entityType);

            void update();

        private:
            bool selected;
        };
    }
}