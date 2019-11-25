#include "pinturas.h"

Pixel defineCorAtual(FILE *comandos){
    Pixel cor;
	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
	
	return cor;
}

void preencheFigura(int x, int y, Imagem *img, Pixel corAtual, Pixel corAnterior){
    /*
    esta função é responsável por preencher figuras
    foi baseada no algoritmo flood fill e adaptada de geeksforgeeks.org  
    */

    //verifica se o ponto dado esta dentro da matriz imagem   
    if(x < 0 || y < 0 || x >= img->largura || y >= img->altura){
        return;
    }

    //verifica se o ponto dado ja foi pintado ou se encontrou alguma barreira
    if(img->matrizImagem[x][y].r != corAnterior.r || img->matrizImagem[x][y].g != corAnterior.g || img->matrizImagem[x][y].b != corAnterior.b){
        return;
    }

    img->matrizImagem[x][y] = corAtual;
    
    /*
    chamada recursiva que preenche a figura da direita para esquerda
    e de cima para baixo
    */
    preencheFigura(x+1, y, img, corAtual, corAnterior);
    preencheFigura(x-1, y, img, corAtual, corAnterior);
    preencheFigura(x, y+1, img, corAtual, corAnterior);
    preencheFigura(x, y-1, img, corAtual, corAnterior);
}

char verificaPosicaodaReta(int dx, int dy){
    //caso inicial.x == final.x
    if(dx == 0){
        return 'X';
    }
    //caso inicial.y == final.y
    else if(dy == 0){
        return 'Y';
    }
    else if(dx >= dy){
        return 'x';
    }
    else{
        return 'y';
    }
}

void pintaPixeldaReta(int TAM, Imagem *img, Pixel cor, Ponto inicial, char inclinacao){
    int x, y;
    x = inicial.x - TAM/2;
    y = inicial.y - TAM/2;

    if(inclinacao == 'Y' || inclinacao == 'y'){
        while(y<=inicial.y+TAM/2){
            if(inicial.x>=0 && y>=0 && inicial.x<img->largura && y<img->altura)
                img->matrizImagem[inicial.x][y] = cor;
            y++;
        }
    }
    else{
        while(x<=inicial.x+TAM/2){
            if(x>=0 && inicial.y>=0 && x<img->largura && inicial.y<img->altura)
                img->matrizImagem[x][inicial.y] = cor;
            x++;
        }
    }
}