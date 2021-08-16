#pragma once

#include <ge/ge.hpp>
#include "../ui/handler.hpp"
#include "entity.hpp"
#include "base/base.hpp"
#include "mob/mob.hpp"

namespace herbglitch {
    namespace entities {
        class Handler : public ge::Handler<Entity>{
        public:
            Handler(ge::Data *data, ge::resource::Spritesheet *spritesheet, ui::Handler *uiHandler);
            ~Handler();

            void update();

        private:
            void checkSlect();

            ge::Data *data;
            ui::Handler *uiHandler;
        };
    }
}