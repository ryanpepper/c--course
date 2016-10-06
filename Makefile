all:
	g++ -Wall -pedantic -ansi bounce.cc -o bounce -std=c++11 -g
	./bounce
