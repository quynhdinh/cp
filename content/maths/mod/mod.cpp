#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
 
 
template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];
 
    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        save_inv[0] = 0;
        save_inv[1] = 1;
 
        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
 
    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();
 
        if (val < SAVE_INV)
            return save_inv[val];
 
        _m_int product = 1;
        int v = val;
 
        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);
 
        return product * save_inv[v];
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
 
const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;
 
 
template<const int &MOD>
struct combinatorics {
    using combo_int = _m_int<MOD>;
 
    vector<combo_int> _factorial = {1}, _inv_factorial = {1};
 
    void prepare_factorials(int64_t maximum) {
        static int64_t prepared_maximum = 0;
 
        if (maximum <= prepared_maximum)
            return;
 
        // Prevent increasing prepared_maximum by only 1 each time.
        maximum = max(maximum, int64_t(1.01L * prepared_maximum));
        _factorial.resize(maximum + 1);
        _inv_factorial.resize(maximum + 1);
 
        for (int64_t i = prepared_maximum + 1; i <= maximum; i++)
            _factorial[i] = i * _factorial[i - 1];
 
        _inv_factorial[maximum] = _factorial[maximum].inv();
 
        for (int64_t i = maximum - 1; i > prepared_maximum; i--)
            _inv_factorial[i] = (i + 1) * _inv_factorial[i + 1];
 
        prepared_maximum = maximum;
    }
 
    combo_int factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _factorial[n];
    }
 
    combo_int inv_factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _inv_factorial[n];
    }
 
    combo_int choose(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
    }
 
    combo_int permute(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[n - r];
    }
 
    combo_int inv_choose(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
    }
 
    combo_int inv_permute(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[n - r];
    }
};
 
combinatorics<MOD> combo;
void test_case(){
    int n, m, k; cin>>n>>m>>k;
    if(k > n){
        cout<<0<<'\n';
        return;
    }
    mod_int res = mod_int(m).pow(k);
    res *= int(combo.choose(n, k));
    cout<<res<<'\n';
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        test_case();
    }

    return 0;
}
