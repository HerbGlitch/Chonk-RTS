#include <ge/ge.hpp>
#include "game/game.hpp"

int main(int argc, char *argv[]){
    ge::Data *data = new ge::Data();

    data->state.add(new herbglitch::Game(data));

    ge::Run(data, 1920, 1080, "Chonk");

    delete data;

    return 0;
}