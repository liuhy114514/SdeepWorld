default: main.cpp constants.hpp Event.hpp interface.hpp Player.hpp SaveSystem.hpp
	g++ main.cpp -o game -std=c++14 -O0 -static
Release: main.cpp constants.hpp Event.hpp interface.hpp Player.hpp SaveSystem.hpp
	g++ main.cpp -o game -std=c++14 -O2 -static
clean:
	del *.o
	del *.exe