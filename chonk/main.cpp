#include <ge/ge.hpp>
#include "game/game.hpp"
#include <stdio.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[]){
    ge::Data *data = new ge::Data();

    data->state.add(new herbglitch::Game(data));

    ge::Run(data, 1920, 1080, "Chonk");

    IMG_Init(0);
    IMG_Quit();

    delete data;

    return 0;
}