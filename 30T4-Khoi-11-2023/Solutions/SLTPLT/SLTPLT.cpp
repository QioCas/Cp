#define console(...) void() // 2023/4/14-19:11:27
#include "bits/stdc++.h" // QioCas
using ll = long long;
using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> G[N];
vector<int> del;
set<int> S;

void Enter() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        G[i].clear();
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        sort(G[i].begin(), G[i].end());
}

void Solve() {
    for(int i = 1; i <= n; ++i) S.insert(i);
    vector<int> scc;
    for(int i = 1; i <= n; ++i) {
        if(S.count(i) == 0) continue;
        queue<int> Q; 
        int cnt = 0;
        Q.push(i), ++cnt, S.erase(i);
        while(Q.size()) {
            int u = Q.front(); Q.pop();
            for(int v : S) {
                if(binary_search(G[u].begin(), G[u].end(), v)) continue;
                Q.push(v), ++cnt, del.push_back(v); 
            }
            for(; del.size(); del.pop_back())
                S.erase(del.back());
        }
        scc.push_back(cnt);
    }   
    sort(scc.begin(), scc.end());
    cout << scc.size() << "\n";
    for(int u : scc) cout << u << " ";
    cout << "\n";
}

signed main() {
    #define task "SLTPLT" 
    if(fopen(task".inp", "r")) 
        freopen(task".inp", "r", stdin), 
        freopen(task".out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    // Ngôn từ vốn được sinh ra để lừa lọc nhau đấy.
    int tt = 1; cin >> tt;
    while(tt--) {
        Enter();
        Solve();
    }
    return 0;
} 
