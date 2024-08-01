name="mario"
dir=~/Cp/StressTest

cd $dir/problems

cd $name/
 
# g++ valid.cpp -o valid -I/home/cas/Cp/StressTest/lib 
g++ gen.cpp  -o gen -I/home/cas/Cp/StressTest/lib
# g++ sol.cpp -o sol
./gen -SUB 2 -K 1 {$1} > test.in
# ./gen > test.in -SUB 1 
# ./valid < test.in
# ./sol < test.in > test.out

echo