#include "imagem.h"

//void criaImagem()

void salvaImagem(FILE *comandos, FILE *arquivoImagem, Pixel **matrizImagem, int largura, int altura){
	char nomeImagem[31];
  	int i=-1, j;
  	getc(comandos);
  	fseek(comandos, 0, SEEK_CUR);
  	getc(comandos);
  	fseek(comandos, 0, SEEK_CUR);
  	do{
    	i++;
    	fscanf(comandos, "%c", &nomeImagem[i]);
    	fseek(comandos, 0, SEEK_CUR);
  	} while(nomeImagem[i]!=34);
  	nomeImagem[i] = 0;
  	arquivoImagem = fopen(nomeImagem, "w");
	if(arquivoImagem == NULL){
		printf("Erro na abertura do arquivo.\n");
		return; 
	}
  	fprintf(arquivoImagem, "P3\n%d %d\n255\n", largura, altura);
  	for(i=0; i<largura; i++){
    	for(j=0; j<altura; j++){
      		fprintf(arquivoImagem, "%d %d %d\n", matrizImagem[i][j].r, matrizImagem[i][j].g, matrizImagem[i][j].b);
    	}
  	}
  	fclose(arquivoImagem);
}

void limpaImagem(FILE *comandos, Pixel **matrizImagem, int largura, int altura){
  	int i, j;
  	Pixel cor;
  	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
  	fseek(comandos, 0, SEEK_CUR);
  	for(i=0; i<largura; i++){
    	for(j=0; j<altura; j++){
      		matrizImagem[i][j].r = cor.r;
      		matrizImagem[i][j].g = cor.g;
      		matrizImagem[i][j].b = cor.b;
    	}
  	}
}