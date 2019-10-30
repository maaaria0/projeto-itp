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

void desenhaCirculo(Ponto centro, FILE comandos, Pixel **matrizImagem, Pixel cor);
void desenhaRetangulo(Ponto p, FILE comandos, Pixel **matrizImagem, Pixel cor);
void desenhaPoligono(FILE comandos, Pixel **matrizImagem, Pixel cor);
void desenhaReta(FILE comandos, Pixel **matrizImagem, Pixel cor);

#endif