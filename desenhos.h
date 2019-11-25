#ifndef DESENHOS_H
#define DESENHOS_H

#include "ponto.h"
#include "pinturas.h"
#include "imagem.h"
#include <math.h>

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor);
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem *img, Pixel cor, int TAM);
void desenhaPoligono(FILE *comandos, Imagem *img, Pixel cor, int TAM);
void desenhaReta(Ponto inicial, Ponto final, Imagem *img, Pixel cor, int TAM);
void desenhaPoligono3D(FILE *comandos, Imagem *img, Pixel cor, int TAM);
void desenhaCurva(FILE *comandos, Imagem *img, Pixel cor);

#endif
