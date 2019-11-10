#include "pinturas.h"

Pixel defineCorAtual(FILE *comandos){
	Pixel cor;
	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
    fseek(comandos, 0, SEEK_CUR);
	
	return cor;
}

void preencheFigura(int x, int y, Imagem *img, Pixel corAtual, Pixel corAnterior){ 
    if(x < 1 || y < 1 || x >= img->largura-1 || y >= img->altura-1){
        return;
    }
    if(img->matrizImagem[x][y].r != corAnterior.r || img->matrizImagem[x][y].g != corAnterior.g || img->matrizImagem[x][y].b != corAnterior.b){
        return;
    }

    img->matrizImagem[x][y] = corAtual;

    preencheFigura(x+1, y, img, corAtual, corAnterior);
    preencheFigura(x-1, y, img, corAtual, corAnterior);
    preencheFigura(x, y+1, img, corAtual, corAnterior);
    preencheFigura(x, y-1, img, corAtual, corAnterior);
}