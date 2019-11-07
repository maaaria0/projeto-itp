#ifndef DESENHOS_H
#define DESENHOS_H

#include "ponto.h"
#include "pinturas.h"
#include "imagem.h"
#include <math.h>

/*typedef struct {
	Ponto centro;
	int raio;
} Circulo;*/

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor);
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem *img, Pixel cor);
void desenhaPoligono(FILE *comandos, Imagem *img, Pixel cor);
void desenhaReta(Ponto inicial, Ponto final, Imagem *img, Pixel cor);

#endif
