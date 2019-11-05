#ifndef DESENHOS_H
#define DESENHOS_H

#include "ponto.h"
#include "pinturas.h"
#include "imagem.h"


typedef struct {
	Ponto centro;
	int raio;
} Circulo;

typedef struct {
	Ponto p;
	int largura;
	int altura;
} Retangulo;

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor);
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem *img, Pixel cor);
void desenhaPoligono(FILE *comandos, Imagem *img, Pixel cor);
void desenhaReta(int xi, int yi, int xf, int yf, Imagem *img, Pixel cor);
void inverte(int *p_1, int *p_2);

#endif
