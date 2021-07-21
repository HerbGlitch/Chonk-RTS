#pragma once

#include <ge/ge.hpp>
#include "selector.hpp"

namespace herbglitch {

    namespace ui {
        class Handler {
        public:
            Handler(ge::Data *data);
            ~Handler();

            void update();
            void render();

            SDL_Rect &getSelectedArea(){ return selectedArea; }

        private:
            void updateSelector();

            ge::Data *data;

            Selector *selector;
            SDL_Rect selectedArea;
        };
    }
}