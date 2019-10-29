#ifndef PINTURAS_H
#define PINTURAS_H

#include "ponto.h"

typedef struct cor {
	int R;
	int G;
	int B;
} Cor;


Cor definirCor(int r, int g, int b);
void mudarCorAtual();
void preencherFigura(Ponto *p);

#endif