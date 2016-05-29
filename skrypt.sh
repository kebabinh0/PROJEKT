#!/bin/bash
./wyslij
str="$(./odbierz | aspell -l pl_PL -a | tail -c 3)"
strpom="*"
strdata="$(date "+%u")"
if [ $strdata -ge 5 ]
then
	if [ "$str" = "$strpom" ]
		then
			echo "Wyraz jest po polsku"
		else 
			echo "Wyraz jest nie po polsku lub nie zaczyna sie od litery"
	fi
	else
		echo "Nie mamy weekendu"
fi
