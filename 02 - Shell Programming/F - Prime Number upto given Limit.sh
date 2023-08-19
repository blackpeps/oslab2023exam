echo "enter a number upto which you want the prime numbers"
read num
count=0
for (( n=2; n<=$num; n++ ))
do
t=1
if [ $n -lt 2 ]
then echo "Please give other  numbers than 0 and 1"
else
for (( i=2; i<$n; i++ ))
do
        if (($n%i==0))
        then
        t=0
        break;
        fi
done
        if [ $t == 1 ]
        then
        echo $n
        count=$((count+1))
        fi
fi
done
#echo "Total prime numbers upto $num are $count "
