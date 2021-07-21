#include "handler.hpp"

namespace herbglitch {
    namespace armies {
        Handler::Handler(ge::Data *data, ui::Handler *uiHandler, sf::Color color): data(data), uiHandler(uiHandler), color(color){
            add(new Base(data, sf::Vector2f(900, 100), BaseType::BARRACKS, 0, color));
            add(new Mob(data, sf::Vector2f(400, 100), MobType::ADVANCED, 1, color));
            add(new Mob(data, sf::Vector2f(500, 100), MobType::ADVANCED, 1, color));
            add(new Mob(data, sf::Vector2f(600, 100), MobType::ADVANCED, 1, color));
            add(new Mob(data, sf::Vector2f(700, 100), MobType::BASIC, 1, color));
            add(new Mob(data, sf::Vector2f(800, 100), MobType::BASIC, 1, color));
        }

        Handler::~Handler(){}

        void Handler::update(){
            updateHandler<ge::Object>();
            checkSlect();
        }

        void Handler::checkSlect(){
            if(uiHandler->getMouse().left != Mouse::RELEASED){ return; }
            for(ge::Object *obj : hTypes){
                sf::RectangleShape selectionArea = uiHandler->getSelectedArea();

                if(obj->getId() == 0){
                    Base *base = (Base *) obj;
                    bool point = selectionArea.getSize().x < 0.5f && selectionArea.getSize().y < 0.5f;
                    bool contains = base->getBase().getGlobalBounds().contains(selectionArea.getPosition());
                    base->select(point && contains);
                }

                if(obj->getId() == 1){
                    Mob *mob = (Mob *) obj;
                    bool contains = selectionArea.getGlobalBounds().intersects(mob->getMob().getGlobalBounds());
                    mob->select(contains);
                }
            }
        }
    }
}