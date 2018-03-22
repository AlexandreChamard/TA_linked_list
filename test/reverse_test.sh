#!/bin/bash

files=('test-reverse.c')

exitt=0

for file in ${files[*]}
do
	bin="bin_"${file:5: -2}
	echo ${file:5: -2}
	gcc -W -Wall -Wextra -g -o $bin $file -L. -l:$1 > /dev/null
	if [[ $? == 0 ]]; then
		./$bin
		if [[ $? == 0 ]]; then
			echo -e '\033[1;92m''SUCCESS\n''\033[0;97m'
		else
			echo -e '\033[1;31m''FAILURE\n''\033[0;97m'
			exitt=1
		fi
	else
		echo "ERROR COMPILE: "$file
		exit 1
	fi
done

if [[ $exitt == 1 ]]; then
	echo 'KO'
else
	echo 'OK'
fi

exit $exitt
