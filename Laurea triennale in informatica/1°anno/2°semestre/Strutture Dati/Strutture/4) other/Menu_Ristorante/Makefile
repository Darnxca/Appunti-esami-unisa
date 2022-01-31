test_menu.exe: ingrediente.o list_ingrediente.o piatto.o list_piatto.o menu.o test_menu.o
	gcc piatto.o list_piatto.o ingrediente.o list_ingrediente.o menu.o test_menu.o -o test_menu.exe

ingrediente.o:	ingrediente.c ingrediente.h
	gcc -c ingrediente.c

list_ingrediente.o:	list_ingrediente.c list_ingrediente.h ingrediente.h
	gcc -c list_ingrediente.c

piatto.o:	piatto.c ingrediente.h piatto.h list_ingrediente.h
	gcc -c piatto.c

list_piatto.o:	list_piatto.c list_piatto.h piatto.h
	gcc -c list_piatto.c

menu.o: menu.c menu.h piatto.h list_piatto.h
	gcc -c menu.c
	
test_menu.o: test_menu.c menu.h piatto.h ingrediente.h
	gcc -c test_menu.c

clean:	
	rm -f test_menu.o menu.o list_ingrediente.o ingrediente.o list_piatto.o piatto.o test_menu.exe
