#include "base.hpp"

namespace herbglitch {
    namespace armies {
        Base::Base(ge::Data *data, sf::Vector2f coords, BaseType baseType, unsigned int id, sf::Color color): ge::Object(data, id), baseType(baseType){
            selected = false;
            base.setOutlineColor(sf::Color::Red);
            
            base.setPosition(coords);
            base.setFillColor(color);

            switch(baseType){
                case BaseType::MAIN:
                    base.setSize(sf::Vector2f(100.0f, 50.0f));
                    break;

                default:
                    base.setSize(sf::Vector2f(50.0f, 50.0f));
                    break;
            }
        }

        Base::~Base(){}

        void Base::update(){
            if(selected){
                base.setOutlineThickness(5.0f);
            }
            else {
                base.setOutlineThickness(0.0f);
            }
        }

        void Base::render(){
            data->window.draw(base);
        }
    }
}