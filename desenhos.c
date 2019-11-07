#include "desenhos.h"

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor){
	int raio;
	fscanf(comandos, " %d", &raio);
	fseek(comandos, 0, SEEK_CUR);

	int x, y, d=1-raio;
	y=raio;
	x=0;
	//img.matrizImagem[centro.x][centro.y] = cor;
	while(y > x){
		img.matrizImagem[x+centro.x][y+centro.y] = cor;
		img.matrizImagem[y+centro.x][x+centro.y] = cor;
		img.matrizImagem[-x+centro.x][-y+centro.y] = cor;
		img.matrizImagem[-y+centro.x][-x+centro.y] = cor;
		img.matrizImagem[-x+centro.x][y+centro.y] = cor;
		img.matrizImagem[x+centro.x][-y+centro.y] = cor;
		img.matrizImagem[-y+centro.x][x+centro.y] = cor;
		img.matrizImagem[y+centro.x][-x+centro.y] = cor;
		if(d<0)
			d+= 2*x + 3;
		else{
			d+= 2*(x-y) + 5;
			y--;
		}
		x++;
	}
}

void desenhaRetangulo(Ponto p, FILE *comandos, Imagem *img, Pixel cor){
    int largura, altura;
    fscanf(comandos, " %d %d", &largura, &altura);
    fseek(comandos, 0, SEEK_CUR);

    Ponto i = p, f;
    f.x = p.x + largura;
    desenhaReta(i, f, img, cor);
    i.x+= largura;
    f.y+= altura;
    desenhaReta(i, f, img, cor);
    i.y+= altura;
    f.x-= largura;
    desenhaReta(i, f, img, cor);
    i.x-= largura;
    f.y-= altura;
    desenhaReta(i, f, img, cor);

    /*desenhaReta(p.x, p.y, p.x + largura, p.y, img, cor);
    desenhaReta((p.x + largura), p.y, (p.x + largura), (p.y + altura), img, cor);
    desenhaReta((p.x + largura), p.y + altura, p.x, (p.y + altura), img, cor);
    desenhaReta(p.x, (p.y + altura), p.x, p.y, img, cor);*/
}

void desenhaPoligono(FILE *comandos, Imagem *img, Pixel cor){
	int N, i;
	//leitura
	fscanf(comandos, " %d", &N);
	fseek(comandos, 0, SEEK_CUR);
	Ponto pontos[N];

	for(i=0; i<N; i++){
		fscanf(comandos, " %d %d", &pontos[i].x, &pontos[i].y);
	}
	fseek(comandos, 0, SEEK_CUR);
	
	for(i=0; i<N-1; i++){
		desenhaReta(pontos[i], pontos[i+1], img, cor);
	}
	//ligar ultimo ponto
	desenhaReta(pontos[0], pontos[N-1], img, cor);
}

void desenhaReta(Ponto inicial, Ponto final, Imagem *img, Pixel cor){

	if(inicial.x > final.x){
		inverteCoordenadas(&inicial.x, &final.x);
		inverteCoordenadas(&inicial.y, &final.y);
	}

	if(inicial.y == final.y){
	    while(inicial.x <= final.x){
	        img->matrizImagem[inicial.x][inicial.y] = cor;
	        inicial.x++;
	    }
	}
	else if(inicial.x == final.x){
	    if(inicial.y > final.y){
        	inverteCoordenadas(&inicial.y, &final.y); //como xi=xf não fará diferença
        }
	    while(inicial.y <= final.y){
	        img->matrizImagem[inicial.x][inicial.y] = cor;
	        inicial.y++;
	    }
    }
	else{
		float inclinacao = 0;
		int aux = 1, menorY=inicial.y, maiorY=final.y;

		if(inicial.y > final.y){
			aux = -1;
			inverteCoordenadas(&maiorY, &menorY);
		}

		if(final.x-inicial.x >= aux*(final.y-inicial.y)){
			while(inicial.x <= final.x){
				img->matrizImagem[inicial.x][inicial.y] = cor;
				inclinacao += (final.y - inicial.y)*1.0/(final.x - inicial.x); //se yf<yi a inclinação será negativa
				if(inclinacao >= 1 || inclinacao <= -1){
					inicial.y+= aux; //se yi>yf, então o mesmo deve decrementar até chegar em yf
					inclinacao-= aux;
				}
				inicial.x++;
			}
		}
		else{//se a diferença de y for maior que a diferença de x
			while(menorY <= maiorY){
				img->matrizImagem[inicial.x][inicial.y] = cor;
				inclinacao += (final.x - inicial.x)*1.0/(final.y - inicial.y);
				if(inclinacao >= 1 || inclinacao <= -1){
					inicial.x++;
					inclinacao-= aux;
				}
				inicial.y+= aux;
				menorY++;
			}
		}
	}
}