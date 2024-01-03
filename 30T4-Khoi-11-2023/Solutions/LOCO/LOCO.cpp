#define console(...) void() // 2023/4/14-19:1:7
#include "bits/stdc++.h" // QioCas
using ll = long long;
using namespace std;

const int N = 1e5 + 5;
const ll inf = 1LL << 61;
int n, p;
ll a[3][N], dp[3][N];

void Enter() {
    cin >> n >> p;
    for(int rot = 0; rot < 3; ++rot)
        for(int i = 1; i <= n; ++i)
            cin >> a[rot][i];
}

void Solve() {
    for(int i = 1; i <= n + 1; ++i) {
        ll retMID = -inf, retLR = -inf;
        for(int j = max(0, i - p); j < i; ++j)
            retMID = max(retMID, dp[1][j]),
            retLR = max({retLR, dp[0][j], dp[2][j]});
        dp[0][i] = retMID + a[0][i];
        dp[1][i] = retLR + a[1][i];
        dp[2][i] = retMID + a[2][i];
    }
    cout << max({dp[0][n + 1], dp[1][n + 1], dp[2][n + 1]}) << "\n";
}

signed main() {
    #define task "LOCO" 
    if(fopen(task".inp", "r")) 
        freopen(task".inp", "r", stdin), 
        freopen(task".out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    // Ngôn từ vốn được sinh ra để lừa lọc nhau đấy.
    Enter();
    Solve();
    return 0;
} 
