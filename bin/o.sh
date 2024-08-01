# Sources: https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html

clear
cd ~/Cp/Stress

memory=524288  # 512MB
stack_size=524288  # 512MB

ulimit -v "${memory}"
ulimit -s "${stack_size}"

set -e

g++ main.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o main
./main < test.in > test.out

diff -Z test.out test.ans > /dev/null || {
    echo "WA on the following test:"
    cat test.in
    echo 
    echo "=============="
    echo "Your answer is:"
    cat test.out
    echo "=============="
    echo "Correct answer is:"
    cat test.ans
}
rm main
diff -Z test.out test.ans > /dev/null || exit 0
echo "Passed test"
