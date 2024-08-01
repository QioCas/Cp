using ll = long long;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

/**
 * random integer numbers
 * default is long long;
 * Ex: randint<int>(1, 10) | randint(1, 23)
*/ 
template <class T = ll>
T randint(ll L, ll R) { 
    return uniform_int_distribution<T>(L, R) (rd);
}

/**
 * random real numbers
 * default is double;
 * Ex: randreal<float>(1, 10) | randreal(1, 23)
*/
template<class T = double> 
T randreal(ll L, ll R) {
    return uniform_real_distribution<T> (L, R) (rd);
}

template<class T> 
bool construe(T u, T v) { return true; }

/**
 * random std::pair numbers
 * default is std::pair<long long, long long>;
 * Ex: randpair(1, 10) | randpair<int, sm>(1, 20), bool sm(int u, int v) { return u < v}
*/
template<class T = ll, bool (*C) (T u, T v) = construe> 
pair<T, T> randpair(ll L, ll R) {
    pair<T, T> ret = {randint<T>(L, R), randint<T>(L, R)};
    do ret = {randint<T>(L, R), randint<T>(L, R)};
    while(C(ret.first, ret.second) == false);
    return ret;
}

/**
 * random array's structure
 * default is long long;
 * Ex: randarr<int, randint<int>>(5, 1, 10) | randarr<pair<int, int>, randpair<int>>(5, 1, 5)
*/
template<class T, T (*Rand) (ll L, ll R)> 
vector<T> randarr(int n, T L, T R) {
    vector<T> a(n);
    for(T& i : a) i = Rand(L, R);
    return a;
}

vector<pair<int, int>> randtree(int n) {
    vector<pair<int, int>> ret;
    for(int i = 2; i <= n; ++i) {
        int u = i;
        int v = randint(1, i - 1);
        if(randint(0, 2)) swap(u, v);
        ret.push_back({u, v});
    }
    return ret;
}

string randstr(int n, char L = 'a', char R = 'z') {
    vector<char> ret = randarr<char, randint<char>>(n, L, R);
    return string(ret.begin(), ret.end());
}