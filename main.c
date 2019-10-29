#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "imagem.h"
#include "pinturas.h"
#include "desenhos.h"

int main()
{
	int largura, altura, i, j;
	char aux[8];
	FILE *arquivoImagem, *comandos;
	Pixel **matrizImagem;
	Ponto *p;

	comandos = fopen("comandos.txt", "r");
	if(comandos == NULL){
		printf("Erro na abertura do arquivo.\n");
		return 1; 
	}

	while(fscanf(comandos, " %s", aux) != EOF){
    	fseek(comandos, 0, SEEK_CUR);
		if(!strcmp(aux, "image")){
      		fscanf(comandos, " %d %d", &largura, &altura);
      		fseek(comandos, 0, SEEK_CUR);
	    	matrizImagem = (Pixel**)calloc(largura, sizeof(Pixel*));
	    	if(matrizImagem == NULL)
		    	return 1;
	    	int i;
	    	for(i=0; i<largura; i++){
		    	matrizImagem[i] = (Pixel*)calloc(altura, sizeof(Pixel));
		    	if(matrizImagem[i] == NULL)
			    	return 1;
	    	}
   		}
		else if(!strcmp(aux, "clear"))
      		limpaImagem(comandos, matrizImagem, largura, altura);
		else if(!strcmp(aux, "save"))
      		salvaImagem(comandos, arquivoImagem, matrizImagem, largura, altura);
      	
      	else if(!strcmp(aux, "circle")){
      		//definir ponto
      		//passar ponto e raio pra funcao desenhar circulo
      	}
      	else if(!strcmp(aux, "polygon")){
      		
      	}
      	else if(!strcmp(aux, "rect")){
      		
      	}
      	else if(!strcmp(aux, "color")){
      		//define cor
      		//altera cor atual
      	}
      	else if(!strcmp(aux, "fill")){
      		
      	}
      	else if(!strcmp(aux, "line")){
      		
      	}
      	/*
      	colocar outras opcoes
      	*/
	}

	for(i=0; i<largura; i++)
		free(matrizImagem[i]);
	free(matrizImagem);

	fclose(comandos);

	return 0;
}