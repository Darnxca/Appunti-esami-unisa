albero: item.o BST.o stack.o coda.o main.o
	gcc item.o BST.o stack.o coda.o main.o -o TestBST

item.o:	item.c
	gcc -c item.c

BST.o:	BST.c
	gcc -c BST.c

coda.o:	coda.c
	gcc -c coda.c

stack.o:	stack.c
	gcc -c stack.c

main.o:	main.c
	gcc -c main.c

clean:
	rm -rf item.o BST.o stack.o coda.o main.o TestBST
