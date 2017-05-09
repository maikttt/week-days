main: main.o week.o
	gcc -o main main.o week.o -lm

main.o: main.c
	gcc -c main.c

week.o: week.c
	gcc -c week.c

clean:
	rm -f *.o