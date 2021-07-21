#include "game.hpp"

namespace herbglitch {
    Game::Game(ge::Data *data): ge::Object(data){
        player = new Player(data);
    }

    Game::~Game(){
        delete player;
    }

    void Game::update(){
        player->update();
    }

    void Game::render(){
        player->render();
    }
}