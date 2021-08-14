#pragma once

#include <ge/ge.hpp>
#include "mobTypes.hpp"

namespace herbglitch {
    namespace armies {
        class Mob : public ge::Object {
        public:
            Mob(ge::Data *data, SDL_Rect coords, MobType mobType, unsigned int id);
            ~Mob();

            void update();
            void render();

            void select(bool selected = true){ this->selected = selected; }

        private:
            MobType mobType;

            bool selected;
        };
    }
}