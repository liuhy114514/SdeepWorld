default: main.cpp constants.hpp Event.hpp interface.hpp Player.hpp SaveSystem.hpp
	g++.exe main.cpp -o game.exe -std=c++14 -O0 -static
Release: main.cpp constants.hpp Event.hpp interface.hpp Player.hpp SaveSystem.hpp
	g++.exe main.cpp -o game.exe -std=c++14 -O2 -static
clean:
	del *.o
	del *.exe