# Sources: https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html

clear
cd /home/cas/Cp/Stress

set -e

# # generator
# g++ gen.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o gen
# ./gen > test.in

# brute force
g++ brute.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o brute
./brute < test.in > test.ans

# main code
g++ main.cpp -DStestMode -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o main
./main  < test.in > test.out

diff -Z test.out test.ans > /dev/null || {
# ~/Cp/Stress/checker > /dev/null || {
    echo "WA on the following test:"
    cat test.in
    echo
    echo "=================="
    echo "Your answer is:"
    cat test.out
    echo "=================="
    echo "Correct answer is:"
    cat test.ans
}

rm brute
# rm gen
rm main
diff -Z test.out test.ans > /dev/null || exit 0
# ~/Cp/Stress/checker > /dev/null || exit 0
echo "Passed test"
