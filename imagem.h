#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int r, g, b;
} Pixel;

typedef struct {
	Pixel **matrizImagem;
	int largura, altura;
} Imagem;

Pixel** criaImagem(FILE *comandos, Imagem *img);
void salvaImagem(FILE *comandos, FILE *arquivoImagem, Imagem img);
void limpaImagem(Pixel cor, Imagem img);

#endif