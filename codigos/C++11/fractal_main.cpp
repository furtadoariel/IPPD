#include <iostream>
#include <thread>
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


    if(argc!=5){
      cout<< "Favor seguir a Chamada: \n ./fractal_main width height iterations nThreads \n";
      exit(1);
    }

    width = atoi(argv[1]);
    height = atoi(argv[2]);
    iterations = atoi(argv[3]);
    nThreads = atoi(argv[4]);
    imagem = fractal_init(imagem, width, height, iterations);
    Tempo temp1;
	
	int intervalo=0;
    int start=0;
    int end=0;

    thread* th = new thread[nThreads]; // cria um vetor com nThreads para execução
    intervalo = width / nThreads;
    end = intervalo;
    
    temp1.start();  // inicia a captura do tempo

    for (int i=0; i < nThreads; i++){
    	th[i] = thread(calculaPixel,width,start,end,height,iterations,imagem);
        start = start+intervalo;
    	end = end+intervalo;
        if(end == 798){
            end+=2;
        }
    }

    for (int i=0; i < nThreads; i++){
    	th[i].join();
    }
    
    temp1.end();    // termina a captura do tempo
    cout << temp1.getTimeElapsed() << endl; // mostra o tempo de relogio
	fractal_close(imagem);
	return 0;
}

