#include "ponto.h"

Ponto definePonto(FILE *comandos){
	Ponto p;
	fscanf(comandos, " %d %d", &p.x, &p.y);
    fseek(comandos, 0, SEEK_CUR);
	
	return p;
}

void inverteCoordenadas(int *c_1, int *c_2){
	//troca c_1 com c_2
	int aux;
	aux = (*c_1);
	(*c_1) = (*c_2);
	(*c_2) = aux;
}