#include "pinturas.h"

Pixel defineCorAtual(FILE *comandos){
	Pixel cor;
	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
    fseek(comandos, 0, SEEK_CUR);
	
	return cor;
}

void preencheFigura(Ponto p, Imagem *img, Pixel cor){ 
    // check current pixel is old_color or not 
    //Ponto pontos[4];
    pontos[0].x = p.x + 1;
    pontos[0].y = p.y;
    pontos[1].x = p.x - 1;
    pontos[1].y = p.y;
    pontos[2].x = p.x;
    pontos[2].y = p.y + 1;
    pontos[3].x = p.x;
    pontos[3].y = p.y - 1;
    
    if(p.x < 0 || p.y < 0){
    	return;
    }

    if (img.matrizImagem[p.x][p.y] != cor) { 
  		img.matrizImagem[p.x][p.y] = cor;
        // recursive call for bottom pixel fill 
        preencheFigura(pontos[0], img, cor); 
  
        // recursive call for top pixel fill 
        preencheFigura(pontos[1], img, cor); 
  
        // recursive call for right pixel fill 
        preencheFigura(pontos[2], img, cor); 
  
        // recursive call for left pixel fill 
        preencheFigura(pontos[3], img, cor); 
    } 
}