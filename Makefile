BIN_DIR := ./src/bin
COMPILED_DIR := ./src/compiled
LIB_DIR := ./src/lib
PROJECT_DIR := ./chonk
INCLUDES = -isystemsrc/include
LIBS = -lmingw32 -lSDL2main -lSDL2 -lsdl2_image
CPPFLAGS = -Wall -Werror
CXX = g++

game := main.cpp game_game.cpp game_player.cpp
ui := game_ui_handler.cpp game_ui_selector.cpp
armies := game_armies_handler.cpp #game_armies_base_base.cpp game_armies_mob_mob.cpp

%.cpp:
	$(CXX) $(INCLUDES) -c $(PROJECT_DIR)/$(subst _,/,$@) -o $(COMPILED_DIR)/$(subst .cpp,,$@).o $(CPPFLAGS)

.PHONY: all
all: compile link

.PHONY: test
test: compile link run

.PHONY: compile
compile: $(game) $(ui) $(armies)

link:
	$(CXX) $(COMPILED_DIR)/*.o -L$(LIB_DIR) -o $(BIN_DIR)/main $(LIBS)

run:
	cd src/bin && ./main.exe
