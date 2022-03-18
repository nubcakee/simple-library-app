VPATH = ../headers 

objects = insert.o show.o file.o

main: main.c $(objects)
	gcc main.c $(objects) -o main

$(shell mkdir ../data)

clean:
	rm -rf *.o