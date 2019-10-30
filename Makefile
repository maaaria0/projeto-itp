all: main

main: ponto.o imagem.o pinturas.o desenhos.o main.c
	gcc main.c -o main ponto.o imagem.o pinturas.o desenhos.o

desenhos.o: ponto.o pinturas.o imagem.o desenhos.c
	gcc desenhos.c -o desenhos ponto.o imagem.o pinturas.o 

pinturas.o: ponto.o imagem.o pinturas.c
	gcc pinturas.c -o pinturas ponto.o imagem.o

imagem.o: imagem.c
	gcc -c imagem.c

ponto.o: ponto.c
	gcc -c ponto.c
	
clean:
	rm -f *.o