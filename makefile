all: basicRun

basicRun: main.cpp game_object.h game_object.cpp
		echo "Did you remember to save everything?\n"
		g++ -std=c++11 -c main.cpp game_object.h game_object.cpp constants.h
		g++ main.o game_object.o -o Snake -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -rf *.o basicRun
