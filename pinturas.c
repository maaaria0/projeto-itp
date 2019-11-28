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
	/*
    esta função é responsável por verificar a posição na qual se encontra a reta,
    horizontal, vertical, diagonal(com dx>=dy ou dy>dx)...
    */

    //caso inicial.x == final.x (vertical)
    if(dx == 0){
        return 'X';
    }
    //caso inicial.y == final.y (horizontal)
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
	/*
    esta função é responsável por pintar determinado ponto da reta, que pode ter mais de
    um pixel dependendo da espessura do pincel
    */

    int x, y;
    //TAM é a espessura do pincel, então fazemos y igual ao ponto inicial menos a espessura dividido por dois
    x = inicial.x - TAM/2;
    y = inicial.y - TAM/2;

    //se a reta estiver na horizontal ou na diagonal(com dy>dx), incrementamos y para criar a espessura do pincel
    if(inclinacao == 'Y' || inclinacao == 'y'){
    	//como já fizemos y = inicial.y-TAM/2, devemos rodar o algoritmo
    	//enquanto y<=inicial.y+TAM/2 para "completar" a espessura do pincel
        while(y<=inicial.y+TAM/2){
        	//verifica se o ponto está dentro das dimensões da imagem, se estiver altera a cor
            if(inicial.x>=0 && y>=0 && inicial.x<img->largura && y<img->altura)
                img->matrizImagem[inicial.x][y] = cor;
            y++;
        }
    }
    //se a reta estiver na vertical ou na diagonal(com dx>=dy), incrementamos x para criar a espessura do pincel
    else{
    	//como já fizemos x = inicial.x-TAM/2, devemos rodar o algoritmo
    	//enquanto x<=inicial.x+TAM/2 para "completar" a espessura do pincel
        while(x<=inicial.x+TAM/2){
        	//verifica se o ponto está dentro das dimensões da imagem, se estiver altera a cor
            if(x>=0 && inicial.y>=0 && x<img->largura && inicial.y<img->altura)
                img->matrizImagem[x][inicial.y] = cor;
            x++;
        }
    }
}