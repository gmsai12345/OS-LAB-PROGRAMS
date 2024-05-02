echo -n "Enter a number: "
read num
fac=1
while [ $num -gt 0 ]
do
    fac=$((fac*num))
    num=$((num-1))
done
echo "Factorial is $fac"
