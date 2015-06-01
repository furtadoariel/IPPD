#include <iostream>
#include "tempo.hpp"

void Tempo::start(){
	gettimeofday(&tStart,NULL); 	// começa a contagem
}

void Tempo::end(){
	gettimeofday(&tEnd,NULL);	// termina
}

double Tempo::getTimeElapsed(){
	double t1 = tStart.tv_sec + ((1.0/1000000) * tStart.tv_usec); 	// jogada para acertar segundos e milisegundos de t1
	double t2 = tEnd.tv_sec + (1.0/1000000) * tEnd.tv_usec;			// e de t2, claro
	elapsedTime = (double)((t2 - t1)/1.0);							// faz a diferenca de tempos
	return elapsedTime;		
}