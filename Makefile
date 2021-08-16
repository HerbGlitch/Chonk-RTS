BIN_DIR := ./src/bin
COMPILED_DIR := ./src/compiled
LIB_DIR := ./src/lib
PROJECT_DIR := ./chonk
INCLUDES = -isystemsrc/include
LIBS = -lSDL2main -lSDL2 -lSDL2_image
CPPFLAGS = -Wall -Werror
CXX = g++

game := main.cpp game_game.cpp game_player.cpp
ui := game_ui_handler.cpp game_ui_selector.cpp
entities := game_entities_handler.cpp game_entities_base_base.cpp game_entities_mob_mob.cpp

%.cpp:
	$(CXX) $(INCLUDES) -c $(PROJECT_DIR)/$(subst _,/,$@) -o $(COMPILED_DIR)/$(subst .cpp,,$@).o $(CPPFLAGS)

all: compile link
.PHONY: all

test: compile link run
.PHONY: test

compile: $(game) $(ui) $(entities)
.PHONY: compile

link:
	$(CXX) $(COMPILED_DIR)/*.o -o $(BIN_DIR)/main $(LIBS)

run:
	cd src/bin && ./main

valgrind:
	cd src/bin && valgrind ./main --track-origins=yes
