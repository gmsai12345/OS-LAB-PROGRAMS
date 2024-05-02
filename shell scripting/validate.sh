echo -n "enter number"
read num
check = $(((n%2)))
if [ check -eq 0 ]
then 
    echo "even number"
else
    echo "odd number"
fi

if [ num -ge 0 ]
then 
    echo "possitive number"
else 
    echo "negative number"
fi
