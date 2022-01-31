stack1:	item.o stack.o list.o test_stack.o
	gcc item.o stack.o list.o test_stack.o -o teststack
item.o:	item.c
	gcc -c item.c
stack.o:	stack.c item.h stack.h
	gcc -c stack.c
list.o:	list.c
	gcc -c list.c
test_steck.o:	item.h stack.h test_stack.c
	gcc -c test_stack.c
clean:
	rm -rf item.o stack.o list.o test_stack.o teststack