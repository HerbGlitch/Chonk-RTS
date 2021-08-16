#pragma once
#include <ge/ge.hpp>
#include "player.hpp"
#include "../DEFINITIONS.hpp"

namespace herbglitch {
    class Game : public ge::Object {
    public:
        Game(ge::Data *data);
        ~Game();

        void update();
        void render();

    private:
        Player *player;
        SDL_Texture *spritesheet;
    };
}