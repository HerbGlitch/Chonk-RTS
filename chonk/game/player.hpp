#pragma once
#include <ge/ge.hpp>
#include "ui/handler.hpp"
#include "entities/handler.hpp"

namespace herbglitch {
    class Player : public ge::Object {
    public:
        Player(ge::Data *data, SDL_Texture *spritesheet);
        ~Player();

        void update();
        void render();

    private:
        ui::Handler *uiHandler;
        entities::Handler *entitiesHandler;
    };
}