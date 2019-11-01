#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>

typedef struct {
	int x;
	int y;
} Ponto;

Ponto definePonto(FILE *comandos);

#endif