#include "imagem.h"

Pixel** criaImagem(FILE *comandos, Imagem *img){
  Pixel **matrizImagem;
  fscanf(comandos, " %d %d", &img->largura, &img->altura);
  fseek(comandos, 0, SEEK_CUR);
	matrizImagem = (Pixel**)calloc(img->largura, sizeof(Pixel*));
	if(matrizImagem == NULL)
    return NULL;
	int i;
	for(i=0; i<img->largura; i++){
	  matrizImagem[i] = (Pixel*)calloc(img->altura, sizeof(Pixel));
		if(matrizImagem[i] == NULL)
      return NULL;
	}
  return matrizImagem;
}

void salvaImagem(FILE *comandos, FILE *arquivoImagem, Imagem img){
	char nomeImagem[31];
  	int i, j;
  	fscanf(comandos, " %s", nomeImagem);
  	fseek(comandos, 0, SEEK_CUR);
  	arquivoImagem = fopen(nomeImagem, "w");
	if(arquivoImagem == NULL){
		printf("Erro na abertura do arquivo.\n");
		return; 
	}
  	fprintf(arquivoImagem, "P3\n%d %d\n255\n", img.largura, img.altura);
  	for(j=img.altura-1; j>=0; j--){
    for(i=0; i<img.largura; i++){
      fprintf(arquivoImagem, "%d %d %d\n", img.matrizImagem[i][j].r, img.matrizImagem[i][j].g, img.matrizImagem[i][j].b);
    }
  }
  fclose(arquivoImagem);
}

void limpaImagem(Pixel cor, Imagem img){
  int i, j;

  for(i=0; i<img.largura; i++){
    for(j=0; j<img.altura; j++){
      img.matrizImagem[i][j] = cor;
    }
  }
}