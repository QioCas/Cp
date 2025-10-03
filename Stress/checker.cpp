#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream out("/home/qiocas/Cp/Stress/test.out");
    ifstream ans("/home/qiocas/Cp/Stress/test.ans");
    double first, second;
    out >> first;
    ans >> second;
    cerr << "respond: " << first << "\n";
    cerr << "answer: " << second << "\n";
    if(abs(first - second) <= (long double) 1e-2) {
        cerr << "Equal!!!\n";
        return 0;
    }
    cerr << "distance = " << abs(first - second) << "\n";
    return 1;
}