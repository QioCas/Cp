#define console(...) void() // 2023/4/10-16:52:30
#include <bits/stdc++.h> // QioCas
using ll = long long;
using namespace std;

const int N = 3e6 + 6;

int n;
int T, a[N];

void Enter() {
    cin >> T >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

deque<int> lmax, lmin;
void Solve() {
    int ans = 0;
    for(int i = 1, j = 1; i <= n; ++i) {
        while(lmax.size() && a[lmax.back()] <= a[i]) lmax.pop_back();
        while(lmin.size() && a[lmin.back()] >= a[i]) lmin.pop_back();
        lmax.push_back(i); lmin.push_back(i);
        while(a[lmax.front()] - a[lmin.front()] > T) {
            ++j;
            if(lmax.front() < j) lmax.pop_front();
            if(lmin.front() < j) lmin.pop_front();
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << "\n";
}

signed main() {
    #define task "CHUNGKHOAN" 
    if(fopen(task".inp", "r")) 
        freopen(task".inp", "r", stdin), 
        freopen(task".out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    // Ngôn từ vốn được sinh ra để lừa lọc nhau đấy.
    Enter();
    Solve();
    return 0;
} 
