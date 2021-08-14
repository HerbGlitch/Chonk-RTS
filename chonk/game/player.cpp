#include "player.hpp"

namespace herbglitch {
    Player::Player(ge::Data *data): ge::Object(data){
        uiHandler = new ui::Handler(data);
        armiesHandler = new armies::Handler(data, uiHandler);
    }

    Player::~Player(){
        delete armiesHandler;
        delete uiHandler;
    }

    void Player::update(){
        uiHandler->update();
        armiesHandler->update();
    }

    void Player::render(){
        armiesHandler->render();
        uiHandler->render();
    }
}