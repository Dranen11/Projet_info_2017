#Makefile Projet

CC=gcc
CXX=g++
CFLAGS=-W -Wall -std=c++14 	-O3 -march=native
LDFLAGS=


Simulation/Simulation.a: Simulation/Numeric_solving.o Simulation/IO.o Simulation/Potential.o
		ar -r $@ $<

Simulation/Numeric_solving.o: Simulation/Numeric_solving.cpp
		$(CXX) -o $@ -c $< $(CFLAGS)

Simulation/Potential.o: Simulation/Potential.cpp
		$(CXX) -o $@ -c $< $(CFLAGS)

Simulation/IO.o: Simulation/IO.cpp
		$(CXX) -o $@ -c $< $(CFLAGS)

clean:
		rm -rf *.o
		rm -rf Simulation/*.o