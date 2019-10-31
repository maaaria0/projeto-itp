#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int r, g, b;
} Pixel;

Pixel** criaImagem(FILE *comandos, int *largura, int *altura);
void salvaImagem(FILE *comandos, FILE *arquivoImagem, Pixel **matrizImagem, int largura, int altura);
void limpaImagem(FILE *comandos, Pixel **matrizImagem, int largura, int altura);

#endif