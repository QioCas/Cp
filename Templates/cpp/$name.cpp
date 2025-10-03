#include <bits/stdc++.h> // QioCas

using namespace std;
using ll = long long;

template <class Tp>
bool minimize(Tp &u, const Tp &v) { return (u > v ? u = v, 1 : 0); }
template <class Tp>
bool maximize(Tp &u, const Tp &v) { return (u < v ? u = v, 1 : 0); }

ll floor_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) { x = -x; y = -y; }
    return x >= 0 ? x / y : (x + 1) / y - 1;
}

ll ceil_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) { x = -x; y = -y; }
    return x <= 0 ? x / y : (x - 1) / y + 1;
}

template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
    template <class... Args>
    Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};

template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
    Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

#define MASK(k) (1LL << (k))
#define BIT(x, k) ((x) >> (k) & 1)
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#include </mnt/d/Cp/Lib/debug.h>
#else
#define print(...) void($year$month$day) /* ignore */
#define debug(...) void($year$month$day) /* ignore */
#endif

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
}