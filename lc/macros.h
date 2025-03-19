#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define TWO(i) (1LL << (i))
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi   first
#define se   second
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