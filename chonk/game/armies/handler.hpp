#pragma once

#include <ge/ge.hpp>
#include "../ui/handler.hpp"
#include "base/base.hpp"
#include "mob/mob.hpp"

namespace herbglitch {
    namespace armies {
        class Handler : public ge::Handler<ge::Object>{
        public:
            Handler(ge::Data *data, ui::Handler *uiHandler, sf::Color color);
            ~Handler();

            void update();

        private:
            void checkSlect();

            ge::Data *data;
            ui::Handler *uiHandler;

            sf::Color color;
        };
    }
}