#include "desenhos.h"

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaPoligono(FILE *comandos, Imagem img, Pixel cor){

}

void inverte(int *p_1, int *p_2){
	//troca p_1 com p_2
	int aux;
	aux = (*p_1);
	(*p_1) = (*p_2);
	(*p_2) = aux;
}

void desenhaReta(FILE *comandos, Imagem *img, Pixel cor){
	int i, xi, yi, xf, yf;
	fscanf(comandos, " %d %d %d %d", &xi, &yi, &xf, &yf);
	fseek(comandos, 0, SEEK_CUR);
	if(yi == yf){
		while(xi<=xf){
			img->matrizImagem[xi][yi] = cor;
			xi++;
		}
	}
	else if(xi == xf){
		while(yi<=yf){
			img->matrizImagem[xi][yi] = cor;
			yi++;
		}
	}
	else{
		float inclinacao = 0;
		int aux = 1, j=yi, i=yf;

		if(xi > xf){
			inverte(&xi, &xf);
			inverte(&yi, &yf);
		}

		if(yi > yf){
			aux = -1;
			inverte(&i, &j); //tive que colocar esse i e j pra colocar no while
			// pois antes não pintava os últimos pixels
		}

		if(xf-xi >= aux*(yf-yi)){//do jeito que eu fiz certamente não dá certo inverter x e y
			while(xi <= xf){
				img->matrizImagem[xi][yi] = cor;
				inclinacao += (yf - yi)*1.0/(xf - xi);
				if(inclinacao >= 1 || inclinacao <= -1){
					yi+= aux; //se yi>yf, então o mesmo deve decrementar até chegar em yf
					inclinacao-= aux; //se yf<yi a inclinação será negativa
				}
				xi++;
			}
		}
		else{//se aux*(yi-yf) > xf-xi
			while(j <= i){
				img->matrizImagem[xi][yi] = cor;
				inclinacao += (xf - xi)*1.0/(yf - yi);
				if(inclinacao >= 1 || inclinacao <= -1){
					xi++;
					inclinacao-= aux; //se yf<yi a inclinação será negativa
				}
				yi+= aux; //se yi>yf, então o mesmo deve decrementar até chegar em yf
				j++;
			}
		}
	}
}