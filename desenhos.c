#include "desenhos.h"

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor){

}
void desenhaRetangulo(Ponto p, FILE *comandos, Imagem *img, Pixel cor){
    int largura, altura;
    fscanf(comandos, " %d %d", &largura, &altura);
    fseek(comandos, 0, SEEK_CUR);
    desenhaReta(p.x, p.y, p.x + largura, p.y, img, cor);
    desenhaReta((p.x + largura), p.y, (p.x + largura), (p.y + altura), img, cor);
    desenhaReta((p.x + largura), p.y + altura, p.x, (p.y + altura), img, cor);
    desenhaReta(p.x, (p.y + altura), p.x, p.y, img, cor);
}
void desenhaPoligono(FILE *comandos, Imagem *img, Pixel cor){
	int N, i, p;
	//leitura
	fscanf(comandos, " %d", &N);
	fseek(comandos, 0, SEEK_CUR);
	p= N*2;
	int pontos[p];
	for(i=0; i<p; i++){
		fscanf(comandos, " %d", &pontos[i]);
	}
	fseek(comandos, 0, SEEK_CUR);
	
	for(i=0; i<N; i++){
		desenhaReta(pontos[i], pontos[i+1], pontos[i+2], pontos[i+3], img, cor);
	}
	//ligar ultimo ponto
	desenhaReta(pontos[0], pontos[1], pontos[p-2], pontos[p-1], img, cor);
}

void inverte(int *p_1, int *p_2){
	//troca p_1 com p_2
	int aux;
	aux = (*p_1);
	(*p_1) = (*p_2);
	(*p_2) = aux;
}

void desenhaReta(int xi, int yi, int xf, int yf, Imagem *img, Pixel cor){
	/*int i, xi, yi, xf, yf;
	fscanf(comandos, " %d %d %d %d", &xi, &yi, &xf, &yf);
	fseek(comandos, 0, SEEK_CUR);*/
	int i;
	if(yi == yf){
	    if(xi>xf){
	        while(xi>=xf){
	            img->matrizImagem[xi][yi] = cor;
                xi--;
	        }
	    }
	    else{
	        while(xi<=xf){
                img->matrizImagem[xi][yi] = cor;
                xi++;
            }
	    }

	}
	else if(xi == xf){
	    if(yi>yf){
            while(yi>=yf){
                img->matrizImagem[xi][yi] = cor;
                yi--;
            }
        }
        else{
            while(yi<=yf){
                img->matrizImagem[xi][yi] = cor;
                yi++;
            }
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