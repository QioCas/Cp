#define console(...) void() // 2023/4/10-16:41:23
#include <bits/stdc++.h> // QioCas
using ll = long long;
using namespace std;

const int N = 1e5 + 5;

vector<int> G[N];
int n, k;
int states[N], touch[N];

void Enter() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> states[i];
    for(int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        G[v].push_back(u);
    }
}

int DFS(int u, int p) {
    int ret = 0;
    for(auto V = G[u].begin(); V != G[u].end(); ++V) {
        if(*V == p) continue;
        ret ^= DFS(*V, u);
    }
    if(u != 1) states[u] ^= ret;
    return ret ^ touch[u];
}

void Solve() {
    for(int i = 1; i <= k; ++i) {
        int x; cin >> x;
        touch[x] ^= 1;
    }
    DFS(1, 1);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += states[i];
    cout << ans << "\n";
}

signed main() {
    #define task "SOFTWARE" 
    if(fopen(task".inp", "r")) 
        freopen(task".inp", "r", stdin), 
        freopen(task".out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    // Ngôn từ vốn được sinh ra để lừa lọc nhau đấy.
    Enter();
    Solve();
    return 0;
} 
