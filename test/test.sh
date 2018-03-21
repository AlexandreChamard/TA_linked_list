#!/bin/bash

if [[ $1 == '-h' || $1 == '-help' || $1 == '--help' ]]; then
	printf '\n%s:

	Need a liblist.a and a list.h in the root.
	Compile all files named test-*.c into bin_*.c and launch them.

	If any argument is given, print the verbose.\n\n' $0
	exit 0
fi

for file in test-*.c
do
	if [[ $file == 'test-*.c' ]]; then
		echo 'NO TEST FILE'
		exit 0
	fi
	bin="bin_"${file:5: -2}
	echo ${file:5: -2}
	gcc -W -Wall -Wextra -g -o $bin $file -L. -llist > /dev/null
	if [[ $? == 0 ]]; then
		if [[ $1 ]]; then
			./$bin
		else
			./$bin > /dev/null
		fi
		if [[ $? == 0 ]]; then
			echo -e '\033[1;92m''SUCCESS\n''\033[0;97m'
		else
			echo -e '\033[1;31m''FAILURE\n''\033[0;97m'
		fi
	else
		echo "ERROR COMPILE: "$file
		exit 1
	fi
done
exit 0
