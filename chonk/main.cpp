#include <ge/ge.hpp>
#include "game/game.hpp"

int main(int argc, char *argv[]){
    ge::Data *data = new ge::Data();

    ge::Run<herbglitch::Game>(data, 1920, 1080, "Chonk");

    delete data;

    return 0;
}