#!bin/bash

INVALID_MAPS=$(find maps_bonus/invalid -type f)
VALID_MAPS=$(find maps_bonus/valid -type f)
touch Valgrind_Result.txt
VALRESULT=Valgrind_Result.txt
GREEN='\033[0;32m'
RED='\033[0;31m'

make bonus > /dev/null
clear

echo -e "\n                                        MAP TESTER               \n"
echo -e "Test Invalid Maps with Valgrind (Press 1)\nRun Valid Maps with Valgrind (Press 2)\nQuit (Press 3)"
read input
if [ -z "$input" ]
then
	exit 130
fi
trap "rm $VALRESULT" EXIT
printf "\n"
if [ $input == '1' ]
then
	echo -e "Test Invalid Maps with Valgrind:\n"
	for i in $INVALID_MAPS; do
		map_basename="${i##*/}"
    	valgrind ./cub3D $i &> Valgrind_Result.txt
		RESULT=$(cat Valgrind_Result.txt | grep "All heap blocks")
		if [[ "$RESULT" == *"All heap blocks were freed -- no leaks are possible"* ]]
		then
			printf "${GREEN}[OK] Map: $map_basename\n"
		else
			printf "${RED}[KO] Map: $map_basename\n"
		fi
	done
elif [ $input == '2' ]
then
	echo -e "Run Valid Maps with Valgrind:\n"
	for i in $VALID_MAPS; do
		map_basename="${i##*/}"
    	valgrind ./cub3D $i &> Valgrind_Result.txt
		RESULT=$(cat Valgrind_Result.txt | grep "All heap blocks")
		if [[ "$RESULT" == *"All heap blocks were freed -- no leaks are possible"* ]]
		then
			printf "${GREEN}[OK] Map: $map_basename\n"
		else
			printf "${RED}[KO] Map: $map_basename\n"
		fi
	done
else
	exit 0
fi
exit 0