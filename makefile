a.out: create_re_nodes.o create.o display.o main.o restore.o save.o search.o sll_fucntions.o update.o validation.o
	gcc create_re_nodes.o create.o display.o main.o restore.o save.o search.o sll_fucntions.o update.o validation.o -o a.out

create_re_nodes.o: create_re_nodes.c inverted.h
	gcc -c create_re_nodes.c

create.o: create.c inverted.h
	gcc -c create.c

display.o: display.c inverted.h
	gcc -c display.c

main.o: main.c inverted.h
	gcc -c main.c

restore.o: restore.c inverted.h
	gcc -c restore.c

save.o: save.c inverted.h
	gcc -c save.c

search.o: search.c inverted.h
	gcc -c search.c

sll_fucntions.o: sll_fucntions.c inverted.h
	gcc -c sll_fucntions.c

update.o: update.c inverted.h
	gcc -c update.c

validation.o: validation.c inverted.h
	gcc -c validation.c
clean:
	rm -f *.o a.out