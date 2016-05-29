#!/bin/bash
if [ $# != 0 ]
	then
		x=$($1/ipcmd/bin/ipcmd msgget)
		echo "Podaj wiadomosc"
		read wpisz
		$1/ipcmd msgsnd -q $x $wpisz
		$1/ipcmd msgrcv -q $x
		echo

else
	echo "Podaj sciezke do ipcmd, jezeli znajduje sie w katalogu ze skryptem wystarczy ."
fi
