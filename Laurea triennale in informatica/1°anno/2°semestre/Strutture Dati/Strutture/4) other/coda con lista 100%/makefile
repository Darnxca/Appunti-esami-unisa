testcoda:	item.o coda.o testTail.o
	gcc item.o coda.o testTail.o -o testTail
item.o:	item.c
	gcc -c item.c
coda.o:	coda.c
	gcc -c coda.c
testTail.o:	testTail.c
	gcc -c testTail.c
clean:
	rm -rf item.o coda.o testTail.o testTail
