
odbierz - Odbiera komunikat z kolejki.

wyslij  - Wysyla komunikat do kolejki.

apiipc.sh - Przesyla komunikat wpisywany ze standardowego wejscia do kolejki i odbiera go po czym wyswietla.
W argumencie skryptu nalezy podac adres do katalogu, w którym znajduje sie katalog ipcmd (jesli jest to katalog biezacy wystarczy kropka)

skrypt.sh - Zawiera wywolanie programów odbierz i wyslij wraz ze sprawdzeniem czy komunikat jest w jezyku polskim (aspell).

Makefile - Buduje odbierz i wyslij.