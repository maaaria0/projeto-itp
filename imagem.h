#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int r, g, b;
} Pixel;

typedef struct{
	int x, y;
} Ponto;

//void criaImagem();
void salvaImagem(FILE *comandos, FILE *arquivoImagem, Pixel **matrizImagem, int largura, int altura); //save
void limpaImagem(FILE *comandos, Pixel **matrizImagem, int largura, int altura); //clear

#endif