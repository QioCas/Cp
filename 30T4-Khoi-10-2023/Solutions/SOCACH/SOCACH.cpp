#define console(...) void() // 2023/4/10-16:1:26
#include <bits/stdc++.h> // QioCas
using ll = long long;
using namespace std;
using II = pair<int, int>;

#define x first
#define y second

const int N = 1e3 + 3, mod = 1e9;

int m, n, k, Q;
II block[11];
int a[N][N];
ll dp[N][N];

vector<II> V  = { {2, -1}, {2, 1}, {1, 2}, {-1, 2} };
void Enter() {
    cin >> m >> n >> k >> Q;
    for(int i = 1; i <= k; ++i)
        cin >> block[i].x >> block[i].y;
    for(int i = 1; i <= k; ++i) {
        int u, v; tie(u, v) = block[i];
        a[u][v] = -1;
    }
}

ll DP(II u, int direct) {
    ll ret = 0;
    if(u.x < 1 || u.y < 1 || u.x > m || u.y > n) 
        return 0;
    if(dp[u.x][u.y] != -1) return dp[u.x][u.y];

    if(a[u.x][u.y] == -1) return dp[u.x][u.y] = 0;
    if(a[u.x][u.y] == 1) return dp[u.x][u.y] = 1;
    for(auto P = V.begin(); P != V.end(); ++P) {
        II v = {u.x + direct * P->x, u.y + direct * P->y};
        ret = (ret + DP(v, direct)) % mod;
    }
    return dp[u.x][u.y] = ret;
}

namespace Sub2 { 
    ll cal() {
        memset(dp, -1, sizeof dp);
        return DP(II(m, n), -1); 
    }

    void main() {
        for(int i = 1; i <= Q; ++i) {
            int u, v; cin >> u >> v;
            if(a[u][v] == -1) cout << 0 << "\n";
            else {
                a[u][v] = 1;
                cout << cal() << "\n";
                a[u][v] = 0;
            }
        }
    }

}; // DPT O(Q * m * n * 4) ~ 100 ^ 3

namespace Sub3 {
    void main() {
        memset(dp, -1, sizeof dp);
        
        if(a[m][n] == 0) a[m][n] = 1;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                if(dp[i][j] == -1)
                    DP(II(i, j), 1);
        for(int i = 1; i <= Q; ++i) {
            int u, v; cin >> u >> v;
            cout << dp[u][v] << "\n";
        }
    }
}; // DPT <O(m * n * 4), O(Q)> ~ 1000 ^ 2

void Solve() {
   if(Q <= 100 && m <= 100 && n <= 100) Sub2::main();
}

signed main() {
    #define task "SOCACH" 
    if(fopen(task".inp", "r")) 
        freopen(task".inp", "r", stdin), 
        freopen(task".out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    // Ngôn từ vốn được sinh ra để lừa lọc nhau đấy.
    Enter();
    Solve();
    return 0;
} 
