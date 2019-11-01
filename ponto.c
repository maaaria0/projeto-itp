#include "ponto.h"

Ponto definePonto(FILE *comandos){
	Ponto p;
	fscanf(comandos, " %d %d", &p.x, &p.y);
    fseek(comandos, 0, SEEK_CUR);
	
	return p;
}

