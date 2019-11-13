#include "pinturas.h"

Pixel defineCorAtual(FILE *comandos){
    Pixel cor;
	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
	
	return cor;
}

//funcao adaptada baseada no algoritmo flood fill 
void preencheFigura(int x, int y, Imagem *img, Pixel corAtual, Pixel corAnterior){
    //verifica se o ponto dado esta dentro da matriz imagem   
    if(x < 1 || y < 1 || x >= img->largura-1 || y >= img->altura-1){
        return;
    }

    //verifica se o ponto dado ja foi pintado ou se encontrou alguma barreira
    if(img->matrizImagem[x][y].r != corAnterior.r || img->matrizImagem[x][y].g != corAnterior.g || img->matrizImagem[x][y].b != corAnterior.b){
        return;
    }

    img->matrizImagem[x][y] = corAtual;

    preencheFigura(x+1, y, img, corAtual, corAnterior);
    preencheFigura(x-1, y, img, corAtual, corAnterior);
    preencheFigura(x, y+1, img, corAtual, corAnterior);
    preencheFigura(x, y-1, img, corAtual, corAnterior);
}