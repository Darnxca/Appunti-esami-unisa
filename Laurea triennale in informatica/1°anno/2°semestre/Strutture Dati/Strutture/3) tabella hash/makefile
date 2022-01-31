Libreria: item.o hash.o elencoLibri.o main.o
	gcc item.o hash.o elencoLibri.o main.o -o Libreria

item.o:	item.c
	gcc -c item.c

hash.o:	hash.c
	gcc -c hash.c

elencoLibri.o:	elencoLibri.c
	gcc -c elencoLibri.c

main.o:	main.c
	gcc -c main.c

clean:
	rm -rf item.o hash.o elencoLibri.o main.o Libreria