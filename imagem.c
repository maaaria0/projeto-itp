#include "imagem.h"

Pixel** criaImagem(FILE *comandos, Imagem *img){
	/*
	esta função é reponsável por criar uma matriz do tipo pixel, que armazenará inicialmente as cores
	dos pixels da imagem final
	*/
	int i;
	Pixel **matrizImagem;
	fscanf(comandos, " %d %d", &img->largura, &img->altura);

	//alocação dinâmica da matriz que armazenará inicialmente as cores dos pixels da imagem final
	matrizImagem = (Pixel**)calloc(img->largura, sizeof(Pixel*));
	if(matrizImagem == NULL)
		return NULL;

	for(i=0; i<img->largura; i++){
		matrizImagem[i] = (Pixel*)calloc(img->altura, sizeof(Pixel));
		if(matrizImagem[i] == NULL)
			return NULL;
	}
	return matrizImagem;
}

void salvaImagem(FILE *comandos, FILE *arquivoImagem, Imagem img){
	//esta função é reponsável por salvar uma imagem no formato .ppm
	char nomeImagem[31];
	int i, j;
	fscanf(comandos, " %s", nomeImagem);

	//abertura do arquivo para imagem, retornando NULL caso haja algum problema
	arquivoImagem = fopen(nomeImagem, "w");
	if(arquivoImagem == NULL){
		printf("Erro na abertura do arquivo.\n");
		return; 
	}

	/*
	impressão do cabeçalho, seguindo a formação específica do arquivo PPM:
	impressão da versão da imagem ppm, das dimensões da imagem e o valor máximo de cada cor
	*/
	fprintf(arquivoImagem, "P3\n%d %d\n255\n", img.largura, img.altura);

	/*
	impressão de uma sequência de triplas RGB para cada um dos pixels.
	a imagem foi impressa de modo que a posição [0][0] da matriz ficasse no canto inferior esquerdo,
	representando o primeiro quadrante do plano cartesiano.
	*/
	for(j=img.altura-1; j>=0; j--){
		for(i=0; i<img.largura; i++){
			fprintf(arquivoImagem, "%d %d %d\n", img.matrizImagem[i][j].r, img.matrizImagem[i][j].g, img.matrizImagem[i][j].b);
		}
	}

	fclose(arquivoImagem);
}

void limpaImagem(Pixel cor, Imagem img){
  	//esta função é reponsável por mudar a cor de todos os pixels de uma imagem
  	int i, j;
  
  	//iguala cada posição, pixel, da matriz da imagem a cor, tripla RGB, recebida na função
	for(i=0; i<img.largura; i++){
  		for(j=0; j<img.altura; j++){
    		img.matrizImagem[i][j] = cor;
  		}
	}
}