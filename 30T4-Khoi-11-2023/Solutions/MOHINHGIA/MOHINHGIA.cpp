#define console(...) void() // 2023/4/14-20:14:39
#include "bits/stdc++.h" // QioCas
using ll = long long;
using namespace std;

const int N = 1e6 + 5;

int n, m;
int p[N], h[N];

int ord[N];
int l[N], r[N], L[N], R[N];
int ans = 0, is_ret[N], nxt[N];

void Enter() { 
    cin >> n >> m; 
    for(int i = 1; i <= n; ++i) cin >> p[i]; 
    for(int i = 1; i <= m; ++i) cin >> h[i]; 
} 

bool cal(int* arr, int u, int v) {
    return arr[u - L[v]] <= arr[u] && arr[u] <= arr[u - R[v]];
}

void Solve() {
    for(int i = 1; i <= n; ++i) { 
        ord[p[i]] = i; 
        l[i] = i - 1, r[i] = i + 1; 
    } 
    for(int i = n; i >= 1; --i) {
        int t = ord[i];
        if(l[t] >= 1) L[i] = i - p[l[t]];
        if(r[t] <= n) R[i] = i - p[r[t]];
        r[l[t]] = r[t];
        l[r[t]] = l[t];
    } 
    for(int i = 2, t = 0; i <= n; ++i) {
        while(t && !cal(ord, i, t + 1)) t = nxt[t];
        if(cal(ord, i, t + 1)) ++t;
        nxt[i] = t;
    }
    for(int i = 1, t = 0; i <= m; ++i) {
        while((t == n) || (t && !cal(h, i, t + 1))) t = nxt[t];
        if(cal(h, i, t + 1)) ++t;
        if(t == n) ++ans, is_ret[i - n + 1] = true;
    }
    cout << ans << "\n";
    for(int i = 1; i <= m; ++i)
        if(is_ret[i] == true)
            cout << i << " ";
} 

signed main() {
    #define task "MOHINHGIA" 
    if(fopen(task".inp", "r")) 
        freopen(task".inp", "r", stdin), 
        freopen(task".out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    // Ngôn từ vốn được sinh ra để lừa lọc nhau đấy.
    Enter();
    Solve();
    return 0;
} 
