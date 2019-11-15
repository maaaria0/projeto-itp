#include "desenhos.h"

void desenhaCirculo(Ponto centro, FILE *comandos, Imagem img, Pixel cor){
	/*
	Esta função é reponsável por desenhar círculos, e, foi baseada no algoritmo do Ponto Médio 
	de Bresenham.
	A função recebe como parâmetros o ponto central do círculo, o arquivo para leitura do raio,
	a imagem na qual o círculo deve ser desenhado e sua cor.
 	*/
	int raio;
	fscanf(comandos, " %d", &raio);

	int x, y, d=1-raio;
	y=raio;
	x=0;

	while(y > x){
		/*
		Algoritmo de Simetria de Ordem 8.
		Como estamos calculando com x=0 e y=raio, um arco de 45º graus com centro na origem,
		devemos somar os pontos centrais de x e y para colocarmos o círculo na posição correta.
		*/
		if(x+centro.x>=0 && y+centro.y>=0 && x+centro.x<img.largura && y+centro.y<img.altura)
			img.matrizImagem[x+centro.x][y+centro.y] = cor;

		if(y+centro.x>=0 && x+centro.y>=0 && y+centro.x<img.largura && x+centro.y<img.altura)
			img.matrizImagem[y+centro.x][x+centro.y] = cor;

		if(-x+centro.x>=0 && -y+centro.y>=0 && -x+centro.x<img.largura && -y+centro.y<img.altura)
			img.matrizImagem[-x+centro.x][-y+centro.y] = cor;

		if(-y+centro.x>=0 && -x+centro.y>=0 && -y+centro.x<img.largura && -x+centro.y<img.altura)
			img.matrizImagem[-y+centro.x][-x+centro.y] = cor;

		if(-x+centro.x>=0 && y+centro.y>=0 && -x+centro.x<img.largura && y+centro.y<img.altura)
			img.matrizImagem[-x+centro.x][y+centro.y] = cor;

		if(x+centro.x>=0 && -y+centro.y>=0 && x+centro.x<img.largura && -y+centro.y<img.altura)
			img.matrizImagem[x+centro.x][-y+centro.y] = cor;

		if(-y+centro.x>=0 && x+centro.y>=0 && -y+centro.x<img.largura && x+centro.y<img.altura)
			img.matrizImagem[-y+centro.x][x+centro.y] = cor;

		if(y+centro.x>=0 && -x+centro.y>=0 && y+centro.x<img.largura && -x+centro.y<img.altura)
			img.matrizImagem[y+centro.x][-x+centro.y] = cor;
		
		//derivada do circulo
		//FALTA EXPLICAR ESSA PARTE
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

    Ponto i = p, f;
    //descricao 
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
}

void desenhaPoligono(FILE *comandos, Imagem *img, Pixel cor){
	int N, i;
	//leitura da quantidade de pontos a ser lidos 
	fscanf(comandos, " %d", &N);
	Ponto pontos[N];
	
	for(i=0; i<N; i++){
		fscanf(comandos, " %d %d", &pontos[i].x, &pontos[i].y);
	}

	//desenho do poligono
	for(i=0; i<N-1; i++){
		desenhaReta(pontos[i], pontos[i+1], img, cor);
	}
	
	//liga ultimo ponto ao primeiro para fechar a figura
	desenhaReta(pontos[0], pontos[N-1], img, cor);
}

void desenhaReta(Ponto inicial, Ponto final, Imagem *img, Pixel cor){
	/*
	Esta função é reponsável por desenhar retas, linhas, e foi baseada no algoritmo de Bresenham.
	A função recebe como parâmetros dois pontos, inicial e final, a imagem na qual a linha deve ser
	desenhada e sua cor. 
	*/
	float inclinacao = 0;
	int dx, dy;
	/*
	A variável aux seŕa responsável por incrementar, se inicial.y < final.y, ou
	decrementar, se inicial.y > final.y, o valor de inicial.y.
	As variáveis menorY e maiorY são responsáveis por armazenar, respectivamente,
	o valor do menor y e o valor do maior y, e, são usadas em um while. Elas são importantes pois
	há casos em que inicial.x < final.x e inicial.y > final.y, logo não são cabíveis de inversão.
	*/
	int aux=1, menorY=inicial.y, maiorY=final.y;

	if(inicial.x > final.x){
		inverteCoordenadas(&inicial.x, &final.x);
		inverteCoordenadas(&inicial.y, &final.y);
	}
	if(inicial.y > final.y){
		inverteCoordenadas(&maiorY, &menorY);
		aux = -1;
	}
	//dx é a diferença de final.x e inicial.x, enquanto dy é a diferença de final.y e inicial.y
	dx = final.x-inicial.x;
	dy = (final.y-inicial.y)*aux;

	if(dx >= dy){
		while(inicial.x <= final.x && (inicial.x>=0 && inicial.y>=0 && inicial.x<img->largura && inicial.y<img->altura)){
			img->matrizImagem[inicial.x][inicial.y] = cor;

			inclinacao += dy*1.0/dx; 
			if(inclinacao >= 1){
				//Ao atingir 1, devemos decrementar a inclinção para repitir o processo
				inclinacao--;
				/*
				Ao incrementar ou decrementar inicial.y, o que dependerá da variável aux,
				devemos decrementar dy, já que a diferença entre final.y e inicial.y ficará menor
				*/
				inicial.y+= aux;
				dy--;
			}
			//Ao incrementar inicial.x devemos decrementar dx, 
			//já que a diferença entre final.x e inicial.x ficará menor
			inicial.x++;
			dx--;
		}
	}
	//Se dy for maior que dx, faremos os mesmos passos anteriores
	//invertendo apenas os papéis de dx e dy, e, x e y nas operações
	else{
		while(menorY <= maiorY && (inicial.x>=0 && inicial.y>=0 && inicial.x<img->largura && inicial.y<img->altura)){
			img->matrizImagem[inicial.x][inicial.y] = cor;

			inclinacao += dx*1.0/dy;
			if(inclinacao >= 1){
				inclinacao--;
				inicial.x++;
				dx--;
			}
			inicial.y+= aux;
			menorY++;
			dy--;
		}
	}
}