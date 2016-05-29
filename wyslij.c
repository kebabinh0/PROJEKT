#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rozmiar 128

typedef struct buforwiad {
	long cos;
	char wiadomosc[rozmiar];
} bufor_wiadomosci;

int main() {
	int nr_kol_wiad;
	int flaga_wiad = IPC_CREAT | 0666;
	key_t klucz;
	bufor_wiadomosci bufor_wyslania;
	size_t wielkosc_buforu;
	
	if((klucz = ftok("wyslij.c", 'B')) == -1) {
		perror("ftok nie dziala");
		return 1;
	}
	
	(void)fprintf(stderr, "\nmsgget: Wywoluje msggeta(%d,\%#o)\n", klucz, flaga_wiad);
	
	if((nr_kol_wiad = msgget(klucz, flaga_wiad)) < 0) {
		perror("msgget nie dal rady");
		return 1;
	}
	else
		(void)fprintf(stderr,"msgget: Udalo sie uruchomic msgget: id kolejki = %d\n",flaga_wiad);
		
	bufor_wyslania.cos = 1;
	

	printf("Wpisz slowo:\n");
	scanf("%s",bufor_wyslania.wiadomosc);
	
	wielkosc_buforu = strlen(bufor_wyslania.wiadomosc) + 1;
	
	if(msgsnd(nr_kol_wiad, &bufor_wyslania, wielkosc_buforu, IPC_NOWAIT) < 0 ) {
		printf("%d, %lx, %s, %lx\n", nr_kol_wiad, bufor_wyslania.cos, bufor_wyslania.wiadomosc, wielkosc_buforu);
		perror("msgsnd");
		return 1;
	}
	else {
		printf("Wyslano wiadomosc %s\n", bufor_wyslania.wiadomosc);
	}
	return 0;

}
	
