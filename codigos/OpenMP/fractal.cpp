#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include "fractal.hpp"

using namespace std;

ppm_t* fractal_init(ppm_t* img, int width, int height, int color){
	int i;
	int j;

	img = (ppm_t*) malloc(sizeof(ppm_t));
	img->data = (pixel_t*) malloc(sizeof(pixel_t) * width * height);

	img->width = width;
	img->height = height;

	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			fractal_insert(img, i, j, color);
		}
	}

	return img;
}

void fractal_insert(ppm_t* img, int x, int y, int color){
	int i = x * img->width + y;

	img->data[i].r = color;
	img->data[i].g = color;
	img->data[i].b = color;
}

void fractal_close(ppm_t* img){
	free(img->data);
	free(img);
}

// void calculaPixel(int width, int wStart, int wEnd, int height,int iterations, ppm_t *img){
// 	int k; 				// controle do numero maximo de iteracoes
// 	complex <float> c; 	// complexo mapeado pelas coordenadas x e y do plano cartesiano
// 	complex <float> z; 	// complexo calculado em funcao das coordenadas x e y e do numero de iteracoes
// 	for(int i = wStart; i < wEnd; i++){
// 		for(int j = 0; j < height; j++){
// 		  	c = complex<float> ((-2 + ((3. / (width - 1)) * i)),((-1 + ((2. / (height - 1)) * j))));
// 			z = complex<float>(0,0);
// 			k = 0;
// 						//verificar se o ponto esta incluido no conjunto de mandelbrot
// 			while((abs(z) < 2) && (k < iterations)){
// 				z = z * z + c;
// 				k++;
// 			}
// 		  				// criacao da matriz imagem
// 			fractal_insert(img, j, i, (iterations - k) * 25);
// 		}
// 	}
// }