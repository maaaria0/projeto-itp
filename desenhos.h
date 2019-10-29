#ifndef DESENHOS_H
#define DESENHOS_H
#include "ponto.h"
#include "pinturas.h"


//trabalhar com int e nao double???

typedef struct circulo {
	Ponto centro;
	int raio;
} Circulo;

typedef struct retangulo {
	Ponto p;
	int largura;
	int altura;
} Retangulo;

typedef struct poligono {
	Ponto p[3];
} Poligono;

typedef struct reta {
	Ponto p[2];
} Reta;

//rever argumentos
Circulo circle(Ponto *centro, int raio);
Retangulo rect(Ponto *p, int b, int h);
Poligono polygon(int valor_i, Ponto *p);
Reta line(Ponto *p);

#endif