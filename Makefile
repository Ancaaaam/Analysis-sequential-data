build: tema1

tema1: tema1.o Tdouble_linked_list.o functii.o
	gcc tema1.o Tdouble_linked_list.o functii.o -o tema1 -lm

tema1.o: tema1.c

Tdouble_linked_list.o: Tdouble_linked_list.h Tdouble_linked_list.c

functii.o: functii.h functii.c
run:
	./tema1

make clean:
	rm -f *.o tema1
