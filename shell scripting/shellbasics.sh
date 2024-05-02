#!/bin/bash
echo -n "enter a number"
read NAME
echo $NAME

# Declare and assign values to the array
array_name=("Zara" "Qadir" "Mahnaz" "Ayan" "Daisy")

# Access an array element
echo ${array_name[1]}

a=20
b=20

# Corrected if condition syntax
if [ "$a" -eq "$b" ]; then
    echo "a is equal to b"
else
    echo "a is not equal to b"
fi

for ((i=0 ; i<5 ; i++)); do
    echo "welcome $i times"
done
counter=$1
factorial=1
# while loop
a=1
while [ $a -lt 5 ]
do
echo "value of a=" $a
a=`expr $a + 1`
done
# do while loop
counter=1

until [ $counter -lt 5 ]
do
echo "interation $counter"
counter = $((counter+1))
done