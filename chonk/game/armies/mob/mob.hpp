#pragma once

#include <ge/ge.hpp>

namespace herbglitch {
    namespace armies {
        enum class MobType { BASIC, ADVANCED };

        class Mob : public ge::Object {
        public:
            Mob(ge::Data *data, sf::Vector2f coords, MobType mobType, unsigned int id, sf::Color color);
            ~Mob();

            void update();
            void render();

            void select(bool selected = true){ this->selected = selected; }

            sf::CircleShape &getMob(){ return mob; }

        private:
            sf::CircleShape mob;
            MobType mobType;

            bool selected;
        };
    }
}