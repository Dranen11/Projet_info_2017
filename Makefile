#Makefile Projet

CC = gcc
CXX = g++
CFLAGS = -W -Wall -std=c++14 -O3 -march=native
LDFLAGS = -L. -lpython2.7


all: Test/Test_Algebra Test/Test_IO SE_Simulation

#######

Simulation/Numeric_solving.o: Simulation/Numeric_solving.cpp
		$(CXX) -o $@ -c $< $(CFLAGS)

Simulation/Potential.o: Simulation/Potential.cpp
		$(CXX) -o $@ -c $< $(CFLAGS)

Simulation/IO.o: Simulation/IO.cpp
		$(CXX) -o $@ -c $< $(CFLAGS)

#######

Test/Test_Algebra: Test/Test_Algebra.cpp
		$(CXX) -o $@ $< $(CFLAGS)

Test/Test_IO: Test/Test_IO.cpp Simulation/IO.o
		$(CXX) $(LDFLAGS) -o $@ $^ $(CFLAGS)		

#######

Python/Graph.o: Python/Graph.cpp
		$(CXX) $(LDFLAGS) -o $@ -c $^ $(CFLAGS)

#######

SE_Simulation: Console/main.cpp Simulation/IO.o Simulation/Potential.o Simulation/Numeric_solving.o Python/Graph.o
		$(CXX) $(LDFLAGS) -o $@ $^ $(CFLAGS)

#######

clean:
		rm -rf *.o
		rm -rf Simulation/*.o
		rm -rf Python/*.o

clean_exec: clean
		rm -rf Simulation/Simulation.a
		rm -rf Test/Test_Algebra
		rm -rf Test/Test_IO
		rm -rf Python/Appel_Script.a
		rm -rf SE_Simulation