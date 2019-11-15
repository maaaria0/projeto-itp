#include "imagem.h"

Pixel** criaImagem(FILE *comandos, Imagem *img){
	/*
  Esta função é reponsável por criar uma matriz do tipo pixel, que armazenará inicialmente as cores
  dos pixels da imagem final.
  A função recebe como parâmentro, o arquivo de comandos para leitura da largura e da altura da imagem,
  e, um ponteiro de uma variável do tipo Imagem.
  */
  int i;
  Pixel **matrizImagem;
  //Leitura da lagura e da altura da imagem
  fscanf(comandos, " %d %d", &img->largura, &img->altura);

  //Alocação dinâmica da matriz que armazenará inicialmente as cores dos pixels da imagem final
	matrizImagem = (Pixel**)calloc(img->largura, sizeof(Pixel*));
	if(matrizImagem == NULL)
    return NULL;

	for(i=0; i<img->largura; i++){
	  matrizImagem[i] = (Pixel*)calloc(img->altura, sizeof(Pixel));
		if(matrizImagem[i] == NULL)
      return NULL;
	}
  //Retorna a matriz alocada na função para uma variável do tipo ponteiro de ponteiro de pixel no main
  return matrizImagem;
}

void salvaImagem(FILE *comandos, FILE *arquivoImagem, Imagem img){
	/*
  Esta função é reponsável por salvar uma imagem no formato .ppm.
  A função recebe como parâmentro, o arquivo de comandos para leitura do nome da imagem,
  o arquivo da imagem, e uma strut do tipo Imagem, que contém a matriz na qual estão sendo
  armazenadas cores de cada pixel da imagem final.
  */
  char nomeImagem[31];
  int i, j;
  //Leitura do nome da imagem
  fscanf(comandos, " %s", nomeImagem);

  //Abertura do arquivo para imagem, retornando NULL caso haja algum problema
  arquivoImagem = fopen(nomeImagem, "w");
	if(arquivoImagem == NULL){
		printf("Erro na abertura do arquivo.\n");
		return; 
	}

  //Impressão do cabeçalho, seguindo a formação específica do arquivo PPM:
  //Impressão da versão da imagem ppm, das dimensões da imagem e o valor máximo de cada cor.
  fprintf(arquivoImagem, "P3\n%d %d\n255\n", img.largura, img.altura);
  //Impressão de uma sequência de triplas RGB para cada um dos pixels.
  //A imagem foi impressa de modo que a posição [0][0] da matriz ficasse no canto inferior esquerdo,
  //representando, assim, algo como o primeiro quadrante do plano cartesiano.
  for(j=img.altura-1; j>=0; j--){
    for(i=0; i<img.largura; i++){
      fprintf(arquivoImagem, "%d %d %d\n", img.matrizImagem[i][j].r, img.matrizImagem[i][j].g, img.matrizImagem[i][j].b);
    }
  }
  //Fechando o arquivo da imagem
  fclose(arquivoImagem);
}

void limpaImagem(Pixel cor, Imagem img){
  /*
  Esta função é reponsável por mudar a cor de todos os pixels de uma imagem,
  recebendo como parâmentro, assim, uma cor e a imagem. 
  */
  int i, j;
  
  //Iguala cada posição, pixel, da matriz da imagem a cor, tripla RGB, recebida na função.
	for(i=0; i<img.largura; i++){
  	for(j=0; j<img.altura; j++){
    	img.matrizImagem[i][j] = cor;
  	}
	}
}