all: struct.o
	gcc -o test struct.o

struct.o: struct.c
	gcc -c struct.c
	
run:
	./test

clean:
	rm *.o
