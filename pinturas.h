#ifndef PINTURAS_H
#define PINTURAS_H

#include "ponto.h"
#include "imagem.h"

Pixel defineCorAtual(FILE *comandos);
void preencheFigura(Ponto p, Pixel **matrizImagem, Pixel cor);

#endif