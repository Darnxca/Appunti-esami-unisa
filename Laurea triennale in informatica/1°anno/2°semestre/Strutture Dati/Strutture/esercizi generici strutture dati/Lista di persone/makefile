test_list:	item.o list.o testmain.o
	gcc item.o list.o testmain.o -o testList
item.o:	item.c
	gcc -c item.c
list.o:	list.c 
	gcc -c list.c
testmain.o:	testmain.c
	gcc -c testmain.c
clean:
	rm -rf item.o list.o testmain.o testList