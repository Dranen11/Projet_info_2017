#Makefile Projet

CC=gcc
CFLAGS=-W -Wall -std=c++11 -O3
LDFLAGS=


Simulation/Simulation.a: Simulation/Algebra.o Simulation/Numeric_solving.o
		ar -r $@ $<

Simulation/Algebra.o: Simulation/Algebra.cpp Simulation/Algebra.h
		$(CC) -o $@ -c $< $(CFLAGS)

Simulation/Numeric_solving.o: Simulation/Numeric_solving.cpp Simulation/Numeric_solving.h
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		rm -rf *.o
