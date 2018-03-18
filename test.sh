#!/bin/bash
clear
for i in `seq 1 10`;
do
	echo "#$i"
	ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
	result=$(./push_swap $ARG | ./checker $ARG)
	if [ $result = "OK" ]
	then
		echo "\033[1;34mOK\033[0m"
	else
		echo "\033[1;31mKO\033[0m"
	fi
	let "x = $(./push_swap $ARG | wc -l | sed 's/ //')"
	if [ $x -le 5500 ]
	then
		echo "Amount of operation: \033[1;33m$x\033[0m"
	elif [ $x -le 7000 ]
	then
		echo "Amount of operation: \033[1;34m$x\033[0m"
	else
		echo "Amount of operation: \033[1;31m$x\033[0m"
	fi
	let "ret = ret + x"
done
for i in `seq 1 90`;
do
	echo "#$(($i + 10))"
	ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
	let "x = $(./push_swap $ARG | wc -l | sed 's/ //')"
	if [ $x -le 5500 ]
	then
		echo "Amount of operation: \033[1;33m$x\033[0m"
	elif [ $x -le 7000 ]
	then
		echo "Amount of operation: \033[1;34m$x\033[0m"
	else
		echo "Amount of operation: \033[1;31m$x\033[0m"
	fi
	let "ret = ret + x"
done
let "ret = ret / 100"
echo "\033[0;32mAverage score = $ret\033[0m"
sleep 5
let "ret = 0"
for i in `seq 1 100`;
do
	echo "#$i"
	ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
	result=$(./push_swap $ARG | ./checker $ARG)
	if [ $result = "OK" ]
	then
		echo "\033[1;34mOK\033[0m"
	else
		echo "\033[1;31mKO\033[0m"
	fi
	let "x = $(./push_swap $ARG | wc -l | sed 's/ //')"
	if [ $x -le 700 ]
	then
		echo "Amount of operation: \033[1;33m$x\033[0m"
	elif [ $x -le 900 ]
	then
		echo "Amount of operation: \033[1;34m$x\033[0m"
	else
		echo "Amount of operation: \033[1;31m$x\033[0m"
	fi
	let "ret = ret + x"
done
let "ret = ret / 100"
echo "\033[0;32mAverage score = $ret\033[0m"
sleep 5
let "ret = 0"
for i in `seq 1 100`;
do
	echo "#$i"
	ARG="`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`"
	result=$(./push_swap $ARG | ./checker $ARG)
	if [ $result = "OK" ]
	then
		echo "\033[1;34mOK\033[0m"
	else
		echo "\033[1;31mKO\033[0m"
	fi
	let "x = $(./push_swap $ARG | wc -l | sed 's/ //')"
	if [ $x -le 12 ]
	then
		echo "Amount of operation: \033[1;33m$x\033[0m"
	else
		echo "Amount of operation: \033[1;31m$x\033[0m"
	fi
	let "ret = ret + x"
done
let "ret = ret / 100"
echo "\033[0;32mAverage score = $ret\033[0m"
