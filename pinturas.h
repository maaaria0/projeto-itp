#ifndef PINTURAS_H
#define PINTURAS_H

#include "ponto.h"
#include "imagem.h"

Pixel defineCorAtual(FILE *comandos);
void preencheFigura(int x, int y, Imagem *img, Pixel corAtual, Pixel corAnterior);

#endif