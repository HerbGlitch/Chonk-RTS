#pragma once

#include "../entity.hpp"

namespace herbglitch {
    namespace entities {
        class Base : public Entity {
        public:
            Base(ge::Data *data, ge::resource::Spritesheet *spritesheet, SDL_Point coords, EntityType entityType);

            void update();

        private:
            bool selected;
        };
    }
}