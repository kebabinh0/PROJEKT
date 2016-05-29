#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rozmiar 128

typedef struct buforwiad {
	long cos;
	char wiadomosc[rozmiar];
} bufor_wiadomosci;

int main() {
	int id_kol_wiad;
	key_t klucz;
	bufor_wiadomosci odebrana;
	
	if((klucz = ftok("wyslij.c", 'B')) == -1) {
		perror("ftok nie dziala\n");
		return 1;
		}
	
	if((id_kol_wiad = msgget(klucz, 0666)) < 0){
		perror("msgget nie dziala\n");
		return 1;
		}
	
	time_t czas;
	char wynik[2];
	struct tm*tmp;
	czas = time(NULL);
	tmp = localtime(&czas);
	char format[] = "%u";
	
	if(czas == ((time_t)-1)) {
		fprintf(stderr, "Nie udalo sie pobrac daty\n");
		return 1;
		}
		
	if(tmp == NULL) {
		perror("localtime nie dziala\n");
		return 1;
	}
	
	if(strftime(wynik, sizeof(wynik), format, tmp) == 0) {
		(void)fprintf(stderr, "strftime zwrocil 0");
		return 1;
	}
		if(msgrcv(id_kol_wiad, &odebrana, rozmiar, 0, 0) < 0) {
			perror("msgrvc napotkal blad\n");
			return 1;
			}
		if((int)wynik[0] > 52) {
			if(((int)odebrana.wiadomosc[0]>= 65 && (int)odebrana.wiadomosc[0]<=90) || ((int)odebrana.wiadomosc[0]>=97 && (int)odebrana.wiadomosc[0]<=122))
				printf("%s", odebrana.wiadomosc);
			}
	else {
		printf("Nie ma weekendu nie ma wiadomosci\n");
	}
	return 0;
	
}
