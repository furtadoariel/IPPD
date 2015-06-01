#ifndef TEMPO_HPP_
#define TEMPO_HPP_


#include <sys/time.h>

class Tempo{
public:
	void start(); 				// metodo que inicia a contagem de tempo
	void end();					// metodo que termina a contagem de tempo
	double getTimeElapsed();	// metodo para recuperar o tempo

private:
	timeval tStart, tEnd;		// atributos de tempo
	double elapsedTime;			// resultado
};

#endif