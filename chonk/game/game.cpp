#include "game.hpp"

namespace herbglitch {
    Game::Game(ge::Data *data): ge::Object(data){
        spritesheet = new ge::resource::Spritesheet(data->renderer, SPRITESHEET);
        player = new Player(data, spritesheet);
    }

    Game::~Game(){
        delete player;
        delete spritesheet;
    }

    void Game::update(){
        player->update();
    }

    void Game::render(){
        player->render();
    }
}