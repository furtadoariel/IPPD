#include <iostream>
#include <complex>
#include <math.h>
#include "fractal.hpp"
#include "tempo.hpp"

using namespace std;

int width = 0;
int height = 0;
int iterations = 0;
int nThreads = 0;

int main(int argc, char *argv[]){

	ppm_t* imagem = 0;


    if(argc!=4){
      cout<< "Favor seguir a Chamada: \n ./fractal_main width height iterations nThreads \n";
      exit(1);
    }

    width = atoi(argv[1]);
    height = atoi(argv[2]);
    iterations = atoi(argv[3]);
    imagem = fractal_init(imagem, width, height, iterations);
    Tempo temp1;
	
    
    temp1.start();  // inicia a captura do tempo

    calculaPixel(width,0,width,height,iterations,imagem);
    
    temp1.end();    // termina a captura do tempo
    cout << temp1.getTimeElapsed() << endl; // mostra o tempo de relogio
	fractal_close(imagem);
	return 0;
}

