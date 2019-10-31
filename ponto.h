#ifndef PONTO_H
#define PONTO_H


typedef struct {
	int x;
	int y;
} Ponto;

Ponto definePonto(FILE *comandos);

#endif