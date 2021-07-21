#pragma once

#include <ge/ge.hpp>

namespace herbglitch {
    namespace armies {
        enum class BaseType { MAIN, BARRACKS };

        class Base : public ge::Object {
        public:
            Base(ge::Data *data, sf::Vector2f coords, BaseType baseType, unsigned int id, sf::Color color);
            ~Base();

            void update();
            void render();

            void select(bool selected = true){ this->selected = selected; }

            sf::RectangleShape getBase(){ return base; }

        private:
            sf::RectangleShape base;
            BaseType baseType;

            bool selected;
        };
    }
}