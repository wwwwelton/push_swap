make
make bonus
clear
printf "\n"
echo "3 => max 3"
echo "==="
count=50
for i in $(seq $count); do
	ARGS=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`
	./push_swap $ARGS | wc -l | tr '\n' ' '
	echo -n "| "
	./push_swap $ARGS | ./checker $ARGS
done
printf "\n"
echo "100 => max 700"
echo "==="
count=50
for i in $(seq $count); do
	ARGS=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	./push_swap $ARGS | wc -l | tr '\n' ' '
	echo -n "| "
	./push_swap $ARGS | ./checker $ARGS
done
printf "\n"
echo "500 => max 5500"
echo "==="
count=50
for i in $(seq $count); do
	ARGS=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	./push_swap $ARGS | wc -l | tr '\n' ' '
	echo -n "| "
	./push_swap $ARGS | ./checker $ARGS
done
printf "\n"
