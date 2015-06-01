fractal_main: fractal_main.o fractal.o tempo.o
	g++ fractal_main.o fractal.o tempo.o -o fractal_main -lm 

fractal.o: fractal.hpp fractal.cpp
	g++ -c -Wall fractal.cpp

tempo.o: tempo.hpp tempo.cpp
	g++ -c -Wall tempo.cpp

fractal_main.o: fractal_main.cpp fractal.hpp
	g++ -c -Wall fractal_main.cpp -std=c++0x

clean: 
	rm *.o fractal_main
