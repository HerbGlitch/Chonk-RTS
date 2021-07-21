# COMPILED_DIR := ./src/compiled
# WIN_PROJECT_DIR := platformer
# PROJECT_DIR := ./$(WIN_PROJECT_DIR)
# INCLUDES = -isystem../../src/include
# LIBS = -lsfml-graphics -lsfml-window -lsfml-system
# CPPFLAGS = -Wall -Werror
# CXX = g++

# ifeq ($(OS),Windows_NT)
# 	SHELL := C:\Windows\system32\cmd
# endif

# ifeq ($(OS),Windows_NT)
# 	SRCS := $(shell dir $(WIN_PROJECT_DIR) *.cpp /b /S)
# else
# 	SRCS := $(shell find $(PROJECT_DIR) -name *.cpp)
# endif

# compile:
# 	$(foreach file, $(SRCS), @echo $(patsubst %\,%,$(file)))

# $(COMPILED_DIR)/%.cpp.o: %.cpp
# 	mkdir -p $(dir $@)
# 	

all: compile link

test: compile link
	main.exe

compile: main_code game

main_code:
	cd src/compiled && g++ -isystem../include -c ../../chonk/main.cpp -o main.o -Wall -Werror

game: ui #armies
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/game.cpp -o game.o -Wall -Werror
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/player.cpp -o player.o -Wall -Werror

ui:
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/ui/handler.cpp -o ui_handler.o -Wall -Werror
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/ui/selector.cpp -o ui_selector.o -Wall -Werror

armies: base mobs
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/armies/handler.cpp -o armies_handler.o -Wall -Werror

base:
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/armies/base/base.cpp -o base_base.o -Wall -Werror

mobs:
	cd src/compiled && g++ -isystem../include -c ../../chonk/game/armies/mob/mob.cpp -o mobs_mob.o -Wall -Werror


link:
	g++ src/compiled/*.o -Lsrc/lib -o main -lmingw32 -lSDL2main -lSDL2
