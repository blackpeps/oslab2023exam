echo "Enter 2 nos:"
read n1
read n2
echo "Select choice"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read choice
case $choice in
  1) 
    echo "Addition"
    result=$((n1 + n2))
    ;;
  2) 
    echo "Subtraction"
    result=$((n1 - n2))
    ;;
  3) 
    echo "Multiplication"
    result=$((n1 * n2))
    ;;
  4) 
    echo "Division"
    result=$((n1 / n2))
    ;;
  *) 
    echo "Error"
    result="Invalid choice"
    ;;
esac
echo $result

