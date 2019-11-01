all: main

main: ponto.o imagem.o pinturas.o desenhos.o main.c
	gcc main.c -o main ponto.o imagem.o pinturas.o desenhos.o

desenhos.o: desenhos.c
	gcc -c desenhos.c

pinturas.o: pinturas.c
	gcc -c pinturas.c

imagem.o: imagem.c
	gcc -c imagem.c

ponto.o: ponto.c
	gcc -c ponto.c
	
clean:
	rm -f *.o
