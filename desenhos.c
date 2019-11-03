#include "desenhos.h"

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaPoligono(FILE *comandos, Imagem img, Pixel cor){

}

void desenhaReta(FILE *comandos, Imagem *img, Pixel cor){ //"algoritmo de bresenham"; precisa de ajustes
	int i, x1, y1, x2, y2;
	fscanf(comandos, " %d %d %d %d", &x1, &y1, &x2, &y2);
	fseek(comandos, 0, SEEK_CUR);
	if(y1 == y2){
		for(i=x1; i<=x2; i++)
			img->matrizImagem[i][y1] = cor;
	}
	else if(x1 == x2){
		for(i=y1; i<=y2; i++)
			img->matrizImagem[x1][i] = cor;
	}
	else{
		int x, y, xf, d, dx, dy, incremento1, incremento2;
		dx = x2 - x1;
		dy = y2 - y1;
		d = 2*dy - dx;
		incremento1 = 2*dy;
		incremento2 = 2*(dy-dx);
		if(x1 > x2){
			x = x2;
			y = y2;
			xf = x1;
		}
		else{
			x = x1;
			y = y1;
			xf = x2;
		}
		img->matrizImagem[x][y] = cor;
		while(x < xf){
			if(d < 0){
				d += incremento1;
				x++;
			}
			else{
				d += incremento2;
				y++;
			}
			img->matrizImagem[x][y] = cor;
		}
	}
}

/*void desenhaReta(FILE *comandos, Imagem *img, Pixel cor){
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
}*/