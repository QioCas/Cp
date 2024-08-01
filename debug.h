string file() {
    FILE* input = freopen("/home/cas/Cp/Stress/test.in", "r", stdin);
    FILE* output = freopen("/home/cas/Cp/Stress/test.out", "w", stdout);
    assert(input); assert(output);
    return "Had read file I/O";
}

#define console(...) { auto __COPIED__ = __VA_ARGS__; cerr << format("L%d: %d = %d\n", __LINE__, #__VA_ARGS__, __COPIED__); }
#define PRINT(...) { cerr << format("%d\n", format(__VA_ARGS__)); }

template<class Tp1, class Tp2> 
ostream& operator << (ostream& cout, pair<Tp1, Tp2> val) {
    return cout << format("(%d %d)", val.first, val.second);
}

template<class Data, class Tp = decltype(declval<Data>().begin())> 
typename enable_if<!is_same<Data, string>::value, ostream&>::type 
operator << (ostream& cout, Data val) {
    for(auto i = val.begin(); i != val.end(); ++i)
        cout << format("%d%d", (i == val.begin() ? "" : " "), *i);
    return cout;
}

template<class Data, class = decltype(declval<Data>().top())> ostream& operator << (ostream& cout, Data val) {
    for(; val.size(); val.pop())
        cout << format("%d%d", val.top(), val.size() == 1 ? "" : " ");
    return cout;
}

template<class Tp> ostream& operator << (ostream& cout, queue<Tp> val) {
    for(; val.size(); val.pop())
        cout << format("%d%d", val.front(), val.size() == 1 ? "" : " ");
    return cout;
}

template<class Data, class Tp = decltype(declval<Data>().begin())> 
string print_vector_utils(const Data& val) {
    vector<decltype(val.begin())> a;
    for(auto i = val.begin(); i != val.end(); ++i) a.push_back(i);
    int sz = a.size();
    string top = " i   |", bot = " val |", mid = "";
    for(int i = 0; i < sz; ++i) {
        top += format(" %d ", i);
        bot += format(" %d ", *a[i]);
        while(bot.size() < top.size()) bot += " ";
        while(top.size() < bot.size()) top += " ";
        bot += "|"; top += "|";
    }
    while(mid.size() < top.size()) mid += "-+"[top[mid.size()] == '|'];
    return format("print array[%d]\n%d\n%d\n%d\n%d", a.size(), top, mid, bot, mid);
}

template<class Data, class Tp = decltype(declval<Data>().begin()->begin())> 
string print_vector_2D_utils(const Data& val) {
    vector<vector<decltype(val.begin()->begin())>> a;
    for(auto i = val.begin(); i != val.end(); ++i) {
        a.push_back(vector<decltype(val.begin()->begin())>());
        a[0].push_back(val.begin()->begin());
        for(auto j = i->begin(); j != i->end(); ++j)
            a.end()[-1].push_back(j);
    }

    string mid = "";
    size_t rows = a.size(), cols = 0, max_len = 0;
    vector<string> table(rows + 1);

    for(size_t row = 0; row < rows; ++row) cols = max(cols, a[row].size());
    
    table[0] = " r\\c "; 
    max_len = max(max_len, table[0].size());
    for(size_t row = 1; row <= rows; ++row) {
        table[row] = format(" %d ", row - 1);
        max_len = max(max_len, table[row].size());
    }
    for(size_t row = 0; row <= rows; ++row) {
        while(table[row].size() < max_len) table[row] += " ";
        table[row] += "|";
    }

    for(size_t col = 0; col < cols; ++col) {
        table[0] += format(" %d ", col);
        max_len = max(max_len, table[0].size());
        for(size_t row = 1; row <= rows; ++row) {
            if(col >= a[row - 1].size()) table[row] += " # ";
            else table[row] += format(" %d ", *a[row - 1][col]);
            max_len = max(max_len, table[row].size());
        }
        for(size_t row = 0; row <= rows; ++row) {
            while(table[row].size() < max_len) table[row] += " ";
            table[row] += "|";
        }
    }

    while(mid.size() < table.back().size()) mid += "-+"[table.back()[mid.size()] == '|'];

    string ans = format("print table[%d][%d]\n", rows, cols);
    for(size_t row = 0; row <= rows; ++row) ans += format("%d\n%d\n", table[row], mid);
    return ans;
}
