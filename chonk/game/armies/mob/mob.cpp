#include "mob.hpp"

namespace herbglitch {
    namespace armies {
        Mob::Mob(ge::Data *data, sf::Vector2f coords, MobType mobType, unsigned int id, sf::Color color): ge::Object(data, id), mobType(mobType) {
            mob.setPosition(coords);
            mob.setRadius(15.0f);
            mob.setFillColor(color);
            mob.setOutlineColor(sf::Color::Red);

            switch(mobType){
                case MobType::ADVANCED:
                    mob.setPointCount(4);
                    break;

                default:
                    mob.setPointCount(3);
                    break;
            }
        }

        Mob::~Mob(){}

        void Mob::update(){
            if(selected){
                mob.setOutlineThickness(5.0f);
            }
            else {
                mob.setOutlineThickness(0.0f);
            }
        }

        void Mob::render(){
            data->window.draw(mob);
        }
    }
}