#pragma once
#include <ge/ge.hpp>
#include "ui/handler.hpp"
#include "armies/handler.hpp"

namespace herbglitch {
    class Player : public ge::Object {
    public:
        Player(ge::Data *data);
        ~Player();

        void update();
        void render();

    private:
        ui::Handler *uiHandler;
        armies::Handler *armiesHandler;
    };
}