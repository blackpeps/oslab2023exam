echo "Enter three values: "
read a
read b
read c
if [ $a -gt $b ] && [ $a -gt $c ]
then
  greatest=$a
elif [ $b -gt $a ] && [ $b -gt $c ]
then
  greatest=$b
else
  greatest=$c
fi
echo "$greatest is greatest"