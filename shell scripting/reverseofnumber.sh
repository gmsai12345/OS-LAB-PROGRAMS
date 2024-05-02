echo -n "Enter a number: "
read num
echo -n "Enter size: "
read size
revnum=0
while [ $size -gt 0 ]
do
    digit=$((num % 10))
    revnum=$((revnum * 10 + digit))
    num=$((num / 10))
    size=$((size - 1))
done
echo "Reversed number is: $revnum"
