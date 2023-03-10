Concessionaria: item.o BST.o stack.o concessionaria.o main.o
	gcc item.o BST.o stack.o concessionaria.o main.o -o Concessionaria

item.o:	item.c
	gcc -c item.c

BST.o:	BST.c
	gcc -c BST.c

stack.o:stack.c
	gcc -c stack.c

concessionaria.o: concessionaria.c
	gcc -c concessionaria.c

main.o:	main.c
	gcc -c main.c

clean:
	rm -rf item.o BST.o stack.o concessionaria.o main.o Concessionaria