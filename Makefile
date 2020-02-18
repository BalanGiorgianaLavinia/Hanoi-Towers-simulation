FLAGS=-g -Wall -Wextra -o 

build:	tema2.c comenzi.c stiva.c sistem.c lista.c
	gcc $^ $(FLAGS) tema2

clean:
	rm -f tema2
