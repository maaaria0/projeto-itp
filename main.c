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
	Pixel corAtual;
    Imagem img;
    Ponto p;

    //leitura do arquivo
	comandos = fopen("comandos.txt", "r");
	if(comandos == NULL){
		printf("Erro na abertura do arquivo.\n");
		return 1; 
	}

	while(fscanf(comandos, " %s", aux) != EOF){
        fseek(comandos, 0, SEEK_CUR);
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
      		preencheFigura(p, img, corAtual);
      	}

      	else if(!strcmp(aux, "line")){
          int xi, yi, xf, yf;
          fscanf(comandos, " %d %d %d %d", &xi, &yi, &xf, &yf);
          fseek(comandos, 0, SEEK_CUR);
      	  desenhaReta(xi, yi, xf, yf, &img, corAtual);
      	}

      	else{
            //??
        }
	}

	for(i=0; i<img.largura; i++){
		free(img.matrizImagem[i]);
  }
	free(img.matrizImagem);

	fclose(comandos);

	return 0;
}
