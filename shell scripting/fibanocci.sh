echo -n "give the N for N terms"
read n
a=0
b=1
next_term=$((a + b))

echo "$a"
echo "$b"

for ((i = 3; i <= n; i++))
do
    echo "$next_term"
    a=$b
    b=$next_term
    next_term=$((a + b))
done
