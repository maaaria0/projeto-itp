#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "imagem.h"
#include "pinturas.h"

Pixel defineCorAtual(FILE *comandos){
	Pixel cor;
	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
    fseek(comandos, 0, SEEK_CUR);
	
	return cor;
}

void preencheFigura(Ponto p, Pixel **matrizImagem, Pixel cor){

}