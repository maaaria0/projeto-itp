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
	Pixel **matrizImagem, corAtual;
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

		else if(!strcmp(aux, "clear")){
                  limpaImagem(comandos, matrizImagem, largura, altura);
            }

		else if(!strcmp(aux, "save")){
                  salvaImagem(comandos, arquivoImagem, matrizImagem, largura, altura);
            }
      	
      	else if(!strcmp(aux, "circle")){
                  p= definePonto(comandos);
      		desenhaCirculo(p, comandos, matrizImagem, corAtual);
      	}

      	else if(!strcmp(aux, "polygon")){
      		desenhaPoligono(comandos, matrizImagem, corAtual);
      	}

      	else if(!strcmp(aux, "rect")){
      		p= definePonto(comandos);
                  desenhaRetangulo(p, comandos, matrizImagem, corAtual);
      	}

      	else if(!strcmp(aux, "color")){
      		corAtual= defineCorAtual(comandos);
      	}

      	else if(!strcmp(aux, "fill")){
                  p= definePonto(comandos);
      		preencheFigura(p, matrizImagem, corAtual);
      	}

      	else if(!strcmp(aux, "line")){
      	     desenhaReta(comandos, matrizImagem, corAtual);
      	}

      	else{
                  //??
            }
	}

	for(i=0; i<largura; i++)
		free(matrizImagem[i]);

	free(matrizImagem);

	fclose(comandos);

	return 0;
}