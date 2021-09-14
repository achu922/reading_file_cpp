proj1: main.o sub.o
	g++ main.o sub.o -o proj1
main.o: main.cpp
	g++ -c main.cpp
sub.o: sub.cpp sub.h
	g++ -c sub.cpp
