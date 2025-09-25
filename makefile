all: mochila.o item.o main.o 
	gcc mochila.o item.o main.c -o main 
moochila.o:
	gcc -c mochila.c -o mochila.o
item.o:
	gcc -c item.c -o item.o
run:
	./main
clean:
	rm *.o
memory:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main