all:
	gcc -o Reverser main.c Reverser.c -Wall -Wextra
clean:
	rm -rf *.o
