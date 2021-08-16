#include "player.hpp"

namespace herbglitch {
    Player::Player(ge::Data *data, SDL_Texture *spritesheet): ge::Object(data){
        uiHandler = new ui::Handler(data);
        entitiesHandler = new entities::Handler(data, spritesheet, uiHandler);
    }

    Player::~Player(){
        delete entitiesHandler;
        delete uiHandler;
    }

    void Player::update(){
        uiHandler->update();
        entitiesHandler->update();
    }

    void Player::render(){
        entitiesHandler->render();
        uiHandler->render();
    }
}