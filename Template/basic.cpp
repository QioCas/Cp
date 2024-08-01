#include <bits/stdc++.h> // QioCas

using namespace std; 
using ll = long long;

void format_utils(string& ans, const string& s, int i) { while(i < int(s.size())) ans += s[i++]; } 
template<class T, class ...U> void format_utils(string& ans, const string& s, int i, T a, U ...b) { while((s[i] != '%' || s[i + 1] != 'd')) ans += s[i++]; stringstream ss; ss << a; ans += ss.str(); i += 2; if(sizeof...(b)) format_utils(ans, s, i, b...); else format_utils(ans, s, i); } 
template<class ...U> string format(const string& s, U ...args) { string ans = ""; format_utils(ans, s, 0, args...); return ans; }
template <class Tp> bool ckmin(Tp &u, const Tp &v) { return (u > v ? u = v, 1 : 0); }
template <class Tp> bool ckmax(Tp &u, const Tp &v) { return (u < v ? u = v, 1 : 0); }
ll fdiv(ll x, ll y) { assert(y != 0); if(y < 0) { x = -x; y = -y; } return x >= 0 ? x / y : (x + 1) / y - 1; }
ll cdiv(ll x, ll y) { assert(y != 0); if(y < 0) { x = -x; y = -y; } return x <= 0 ? x / y : (x - 1) / y + 1; }
template<class Tp, int D = 1> struct Tvector : public vector<Tvector<Tp, D - 1>> { template <class... Args> Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {} };
template <class Tp> struct Tvector<Tp, 1> : public vector<Tp> { Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {} };

#define MASK(k) (1LL << (k))
#define BIT(x, k) ((x) >> (k) & 1)
#define all(x) (x).begin(), (x).end()


#ifdef LOCAL
#include </home/cas/Cp/Lib/debug.h>
#else
#define PRINT(...) void($year$month$day) /* ignore */
#define console(...) void($year$month$day) /* ignore */
#endif

signed main() {
    console(file());
    cin.tie(NULL)->sync_with_stdio(false);

}
