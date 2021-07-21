#pragma once

#include <ge/ge.hpp>

namespace herbglitch {
    namespace ui {
        class Selector {
        public:
            Selector(ge::Data *data);

            void update();
            void render();

            SDL_Rect shape();

        private:
            ge::Data *data;

            SDL_Rect selection;
            Sint32 x, y;
        };
    }
}