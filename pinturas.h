#ifndef PINTURAS_H
#define PINTURAS_H

#include "ponto.h"
#include "imagem.h"

Pixel defineCorAtual(FILE *comandos);
void preencheFigura(int x, int y, Imagem *img, Pixel corAtual, Pixel corAnterior);
void pintaPixeldaReta(int TAM, Imagem *img, Pixel cor, Ponto inicial, char inclinacao);
char verificaPosicaodaReta(int dx, int dy);

#endif