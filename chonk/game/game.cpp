#include "game.hpp"

namespace herbglitch {
    Game::Game(ge::Data *data): ge::Object(data){
        spritesheet = ge::resource::spritesheet(data->renderer, SPRITESHEET);
        player = new Player(data, spritesheet);
    }

    Game::~Game(){
        delete player;
        SDL_DestroyTexture(spritesheet);
    }

    void Game::update(){
        player->update();
    }

    void Game::render(){
        player->render();
    }
}