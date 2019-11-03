#include "desenhos.h"

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaPoligono(FILE *comandos, Imagem img, Pixel cor){

}

void desenhaReta(FILE *comandos, Imagem *img, Pixel cor){
	int i, x1, y1, x2, y2;
	fscanf(comandos, " %d %d %d %d", &x1, &y1, &x2, &y2);
	fseek(comandos, 0, SEEK_CUR);
	if(y1 == y2){
		for(i=x1; i<=x2; i++)
			img->matrizImagem[y1][i] = cor;
	}
	else{
		float inclinacao = 0;
		while(y1 != y2){
			img->matrizImagem[y1][x1] = cor;
			inclinacao += (y2 - y1)*1.0/(x2 - x1);
			if(inclinacao >= 1){
				y1++;
				inclinacao=0;
			}
			x1++;
		}
	}
}