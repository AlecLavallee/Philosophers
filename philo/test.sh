echo "=================================="
echo "||\t\033[1;92mPHILOSOPHER\033[0m\t\t||"
echo "=================================="

echo "=================================="
echo "||  Test 1: error managment     ||"
echo "=================================="
echo "\033[1;93m1#\033[0m./philo"
./philo
echo "\n\033[1;93m2#\033[0m./philo er 421 200 200 1"
./philo er 421 200 200 1
echo "\n\033[1;93m3#\033[0m./philo 2 -421 200 200 1"
./philo 2 -421 200 200 1
echo "\n\033[1;93m4#\033[0m./philo 2 42+1 200 200 1"
./philo 2 42+1 200 200 1
echo "\n\033[1;93m5#\033[0m./philo 2 421 200 200 0"
./philo 2 421 200 200 0

echo "\n=================================="
echo "||  Test 2: test simple         ||"
echo "=================================="
echo "\033[1;93m1#\033[0m./philo 1 300 200 100 1 >>>> SHOULD DIE"
./philo 1 300 200 100 1
echo ">>>> SHOULD DIE\n"
sleep 2
echo "\033[1;93m2#\033[0m./philo 4 305 200 300 1"
./philo 4 305 200 300 1
echo ">>>> SHOULD LIVE\n"
sleep 2
echo "\033[1;93m3#\033[0m./philo 2 300 200 200 5"
./philo 2 300 200 200 5 | grep "died"
echo ">>>> SHOULD DIE\n"
sleep 2
echo "\033[1;93m4#\033[0m./philo 6 410 200 200 10"
./philo 6 410 200 200 10 | grep "eating" | wc -l
echo ">>>> SHOULD EAT (6 x 10 = 60)\n"
sleep 2
echo "\033[1;93m5#\033[0m./philo 5 800 200 200 7"
./philo 5 800 200 200 7 | grep "died" | wc -l
echo ">>>> SHOULD LIVE (ret = 0)\n"
sleep 2

echo "=================================="
echo "||  Test 3: survie moyenne      ||"
echo "=================================="

echo "\033[1;93m1#\tEVEN:\033[0m./philo 4 410 200 200 7"
for i in `seq 1 10`
do
    ./philo 4 410 200 200 1 > logs
    var=`cat logs | grep "died" | wc -l`
    dead=$(($dead + $var))
done
if [ "$dead" = "0" ]
then
echo "\033[1;92mTEST PASS: ${dead}/10 dead.\033[0m\n"
else
echo "\033[1;91mTEST FAIL: ${dead}/10 dead.\033[0m\n"
fi

echo "\033[1;93m2#\tODD:\033[0m./philo 5 800 200 200 7"
for i in `seq 1 10` 
do 
    ./philo 5 800 200 200 7 > logs
    var=$(cat logs | grep "died" | wc -l)
    die=$(($die + $var))
done
if [ "$die" = "0" ]
then
echo "\033[1;92mTEST PASS: ${die}/10 dead.\033[0m\n"
else
echo "\033[1;91mTEST FAIL: ${die}/10 dead.\033[0m\n"
fi

echo "\033[1;93m3#\t100%dead:\033[0m./philo 5 400 200 200 7"
for i in `seq 1 10` 
do 
    ./philo 5 400 200 200 7 > logs
    var=$(cat logs | grep "died" | wc -l)
    d=$(($d + $var))
done
if [ "$d" = "10" ]
then
echo "\033[1;92mTEST PASS: ${d}/10 dead.\033[0m\n"
else
echo "\033[1;91mTEST FAIL: ${d}/10 dead.\033[0m\n"
fi
