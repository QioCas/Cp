# Sources: https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html

memory=524288  # 512MB
stack_size=524288  # 512MB

ulimit -v "${memory}"
ulimit -s "${stack_size}"

clear
cd ~/Cp/Stress
set -e
g++ main.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o main
g++ brute.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o brute
g++ gen.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -I/home/cas/Cp/StressTest/lib -o gen

for((i = 1; i <= 10000; ++i)); do {

    ./gen > test.in 
    ./main  < test.in > test.out
    ./brute < test.in > test.ans


    diff -Z test.out test.ans > /dev/null || {
    # ~/Cp/Stress/checker > /dev/null || {
        echo "WA on the following test:"
        cat test.in
        echo "=================="
        echo "Your answer is:"
        cat test.out
        echo "=================="
        echo "Correct answer is:"
        cat test.ans
        break
    }
    echo "Passed test: "  $i
}
done

rm main
rm gen
rm brute
