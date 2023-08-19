echo "Enter limit for Fibonacci Series: "
read limit
n1=0
n2=1
echo "Fibonacci series:"
echo $n1
i=2
while [ $i -le $limit ]
do
f=$((n1+n2))
n1=$n2
n2=$f
echo $f
i=$((i+1))
done
