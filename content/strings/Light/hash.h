mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

long long MOD = 1e9 + rnd(0, 1e4), BASE = 233 + rnd(0, 1e3);

struct HashString {
    vector<long long> P, H;

    HashString(string &s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++) {
            P[i] = P[i - 1] * BASE % MOD;
        }
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++) {
            H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
        }
    }

    long long query(int l, int r) {
        return (H[r] - H[l - 1] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};
// Usage: HashString hs(s);