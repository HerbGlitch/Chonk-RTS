#pragma once

#include "entity.hpp"
#include "base/base.hpp"
#include "mob/mob.hpp"
#include "../ui/handler.hpp"

namespace herbglitch {
    namespace entities {
        class Handler : public ge::Handler<Entity>{
        public:
            Handler(ge::Data *data, SDL_Texture *spritesheet, ui::Handler *uiHandler);
            ~Handler();

            void update();

        private:
            void checkSlect();

            ge::Data *data;
            ui::Handler *uiHandler;
        };
    }
}