all: odbierz wyslij

odbierz: odbierz.c
	gcc -o odbierz odbierz.c
wyslij: wyslij.c
	gcc -o wyslij wyslij.c
