echo "Enter Number: "
read num
if [ $((num%2)) -eq 0 ]
then
echo "Even number"
else
echo "Odd number"
fi
