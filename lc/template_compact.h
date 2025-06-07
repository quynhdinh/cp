#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define TWO(i) (1LL << (i))
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
template<class X, class Y>
    bool min_self(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool max_self(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
const int MOD = 1e9 + 7;
inline void add_self(int& a, int val) {
    if ((a = (a + val)) >= MOD)
        a -= MOD;
}
inline void sub_self(int& a, int val) {
    if ((a = (a - val)) < 0) a += MOD;
}
void __print(int x) {cout << x;} void __print(long x) {cout << x;} void __print(long long x) {cout << x;} void __print(unsigned x) {cout << x;} void __print(unsigned long x) {cout << x;} void __print(unsigned long long x) {cout << x;} void __print(float x) {cout << x;} void __print(double x) {cout << x;} void __print(long double x) {cout << x;} void __print(char x) {cout << '\'' << x << '\'';} void __print(const char *x) {cout << '\"' << x << '\"';} void __print(const string &x) {cout << '\"' << x << '\"';} void __print(bool x) {cout << (x ? "true" : "false");} template<typename T, typename V> void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}template<typename T> void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";} void _print() {cout << "]\n";} template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}void db(const vector<bool>& v) { bool first = true; string res = "{"; for (int i = 0; i < int(v.size()); i++) { if (!first) res += ", "; first = false; res += to_string(v[i]); } res += "}"; cout<<res<<'\n';}
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
