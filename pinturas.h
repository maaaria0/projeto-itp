#ifndef PINTURAS_H
#define PINTURAS_H

#include "ponto.h"
#include "imagem.h"

Pixel defineCorAtual(FILE *comandos);
void preencheFigura(Ponto p, Imagem img, Pixel cor);

#endif