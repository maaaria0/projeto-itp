#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct {
	int r, g, b;
} Pixel;

//void criaImagem();
void salvaImagem(FILE *comandos, FILE *arquivoImagem, Pixel **matrizImagem, int largura, int altura); //save
void limpaImagem(FILE *comandos, Pixel **matrizImagem, int largura, int altura); //clear

#endif