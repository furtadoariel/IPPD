#ifndef _FRACTAL_HPP
#define _FRACTAL_HPP

typedef struct{
	unsigned char r, g, b;
} pixel_t;

typedef struct {
	short width, height;
	pixel_t* data;
} ppm_t;

ppm_t* fractal_init(ppm_t*, int, int, int);
void fractal_insert(ppm_t*, int, int, int);
void fractal_close(ppm_t*);
void calculaPixel(int, int, int, int, int, ppm_t *);

#endif // _FRACTAL_HPP
