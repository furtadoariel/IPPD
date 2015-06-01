#include <iostream>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
//#include <complex.h>
#include <math.h>
#include <omp.h>
#include "fractal.hpp"
#include "tempo.hpp"

using namespace std;

int width = 0;
int height = 0;
int iterations = 0;
int nThreads = 0;

int main(int argc, char *argv[]){
	int i; // iteracoes das coordenadas x da imagem
	int j; // iteracoes das coordenadas y da imagem
	int k; // controle do numero maximo de iteracoes
	complex <float> c; // complexo mapeado pelas coordenadas x e y do plano cartesiano
	complex <float> z; // complexo calculado em funcao das coordenadas x e y e do numero de iteracoes
	ppm_t* imagem;


    if(argc!=5){
      cout <<"Favor seguir a Chamada: \n ./fractal_main width height iterations nThreads \n" << endl;
      exit(1);
    }

    width = atoi(argv[1]);
    height = atoi(argv[2]);
    iterations = atoi(argv[3]);
    nThreads = atoi(argv[4]);
    
    imagem = fractal_init(imagem, width, height, iterations);
	
	Tempo temp1;
	// percorre todos os pontos da imagem
	omp_set_num_threads(nThreads);
	omp_set_nested(1);
    
    temp1.start();    
        #pragma omp parallel for default(shared) //diretiva para indicar a região de paralelismo
        
        for(i = 0; i < width; i++){
                #pragma omp parallel for default(shared)  private(j, c, z, k)
		for(j = 0; j < height; j++){
		  // mapeamento das coordenadas e valor inicial de z
		  c = complex<float> ((-2 + ((3. / (width - 1)) * i)),((-1 + ((2. / (height - 1)) * j))));
		  z = complex<float>(0,0);
		  k = 0;
		  //verificar se o ponto esta incluido no conjunto de mandelbrot
		  while((abs(z) < 2) && (k < iterations)){
		    z = z * z + c;
		    k++;
		  }
		  
		  // criacao da matriz imagem
		  fractal_insert(imagem, j, i, (iterations - k) * 25);
		}
	}
	temp1.end();
	cout << temp1.getTimeElapsed() << endl;

	fractal_close(imagem);
	return 0;
}
