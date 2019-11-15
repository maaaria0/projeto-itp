#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "imagem.h"
#include "pinturas.h"
#include "desenhos.h"

int main(){
	int i;
  	char aux[8];
	FILE *arquivoImagem, *comandos;
	Pixel corAtual, corAnterior;
  	Imagem img;
  	Ponto p, p2;

  	//abertura do arquivo com os comandos a serem lidos e executados
	comandos = fopen("comandos.txt", "r");
	if(comandos == NULL){
		printf("Erro na abertura do arquivo.\n");
		return 1; 
	}

	while(fscanf(comandos, " %s", aux) != EOF){	
	    if(!strcmp(aux, "image")){
	  		img.matrizImagem = criaImagem(comandos, &img);
	  		if(img.matrizImagem == NULL){
	  			printf("Erro na criação da imagem.\n");
	  			return 1;
	  		}
		}

		else if(!strcmp(aux, "clear")){
	      	corAtual= defineCorAtual(comandos);
	      	limpaImagem(corAtual, img);
	    }

		else if(!strcmp(aux, "save")){
	      	salvaImagem(comandos, arquivoImagem, img);
	    }
	      	
	  	else if(!strcmp(aux, "circle")){
	      	p= definePonto(comandos);
	  		desenhaCirculo(p, comandos, img, corAtual);
	  	}

	  	else if(!strcmp(aux, "polygon")){
	  		desenhaPoligono(comandos, &img, corAtual);
	  	}

	  	else if(!strcmp(aux, "rect")){
	  		p= definePonto(comandos);
	      	desenhaRetangulo(p, comandos, &img, corAtual);
	  	}

	  	else if(!strcmp(aux, "color")){
	  		corAtual= defineCorAtual(comandos);
	  	}

	  	else if(!strcmp(aux, "fill")){
	      	p= definePonto(comandos);
	      	corAnterior = img.matrizImagem[p.x][p.y];
	  		preencheFigura(p.x, p.y, &img, corAtual, corAnterior);
	  	}

	  	else if(!strcmp(aux, "line")){
	      	p = definePonto(comandos);
	      	p2 = definePonto(comandos);
	  	  	desenhaReta(p, p2, &img, corAtual);
	  	}

	}

	//liberação do espaço alocado na memória
	for(i=0; i<img.largura; i++){
		free(img.matrizImagem[i]);
  	}
	free(img.matrizImagem);
	
	//fechando o arquivo com os comandos
	fclose(comandos);

	return 0;
}
