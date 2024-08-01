#include <bits/stdc++.h> // QioCas

#ifdef LOCAL
#include </home/cas/Cp/Lib/debug.h>
#else
#define console(...) void(10062006)
#endif

using namespace std;
using ll = long long;

const int N = 1e6 + 6;
 
int p[N], h[N], pos[N], prv[N], nxt[N], l_pred[N], l_succ[N], partial[N];
vector<int> matches;
 
inline bool can_extend(int i, int j, int *v) {
	return ((!l_pred[j + 1] || v[i - l_pred[j + 1]] < v[i]) && (!l_succ[j + 1] || v[i] < v[i - l_succ[j + 1]]));
}

int main() {
    if(ifstream("MOHINHGIA.inp")) {
        freopen("MOHINHGIA.inp", "r", stdin);
        freopen("MOHINHGIA.out", "w", stdout);
    }

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x); --x;
		p[i] = x;
		pos[x] = i;
		prv[x] = x - 1, nxt[x] = x + 1;
	}

	for (int i = 0; i < m; i++) scanf("%d", h + i);
 
	for (int i = n - 1; ~i; i--) {
		if (~prv[p[i]]) {
			l_pred[i] = i - pos[prv[p[i]]];
			nxt[prv[p[i]]] = nxt[p[i]];
		}
		if (nxt[p[i]] != n) {
			l_succ[i] = i - pos[nxt[p[i]]];
			prv[nxt[p[i]]] = prv[p[i]];
		}
	}
 
	for (int i = 1, j = partial[0] = -1; i < n; i++) {
		while (~j && !can_extend(i, j, p)) j = partial[j];
		if (can_extend(i, j, p)) j++;
		partial[i] = j;
	}
 
	for (int i = 0, j = -1; i < m; i++) {
		while (~j && !can_extend(i, j, h)) j = partial[j];
		if (can_extend(i, j, h)) j++;
		if (j == n - 1) {
			matches.push_back(i - n + 2);
			j = partial[j];
		}
	}
 
	printf("%d\n", matches.size());
	for (int i : matches) printf("%d ", i);
	printf("\n");
	return 0;

    return 0;
}

/*
6 12
2 5 3 4 1 6
10 45 25 30 5 47 31 35 4 50 33 20
*/

////////////////////////////////////////////////////////////////////////////
//  Nhân quả không nợ chúng ta thức gì, cho nên xin đừng oán giận   ////////
//                                   _
//                                _oo0oo_
//                               o8888888o
//                               88” . “88
//                               (| -_- |)
//                               O\  =  /O
//                            ____/'---'\____
//                          .'  \\|     |//  '.
//                         /  \\|||  :  |||//  \
//                        /  _||||| -:- |||||_  \
//                        |   | \\\  -  /'| |   |
//                        | \_|  `\`---'//  |_/ |
//                        \  .-\__ `-. -'__/-.  /
//                      ___`. .'  /--.--\  `. . '___
//                   ."" '<  `.___\_<|>_/___.'  _> \"".
//                  | | :  `- \`. ;`. _/; .'/  /  .' ; |
//                  \  \ `-.   \_\_`. _.' _/_/  -' _.' /
//===================`-.`___`-.__\ \___   /__.-'_.'_.-'===================//
//                                `=--=-'
 
// Đức Phật nơi đây phù hộ code con chạy không Bugs. Nam mô a di đà Phật.
 
//
//                      _.-/`)
//                     // / / )
//                  .=// / / / )
//                 //`/ / / / /
//                // /    `  /
//               ||         /
//              ||         /
//               \\       /
//                ))    .'
//               //     /
//
