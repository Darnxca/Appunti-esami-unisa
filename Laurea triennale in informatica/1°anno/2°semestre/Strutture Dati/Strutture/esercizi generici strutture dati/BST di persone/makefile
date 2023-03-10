Anagrafe: item.o BST.o stack.o RegistroAnagrafe.o main.o
	gcc item.o BST.o stack.o RegistroAnagrafe.o main.o -o Anagrafe

item.o:	item.c
	gcc -c item.c

BST.o:	BST.c
	gcc -c BST.c

stack.o:stack.c
	gcc -c stack.c

RegistroAnagrafe.o: RegistroAnagrafe.c
	gcc -c RegistroAnagrafe.c

main.o:	main.c
	gcc -c main.c

clean:
	rm -rf item.o BST.o stack.o RegistroAnagrafe.o main.o Anagrafe