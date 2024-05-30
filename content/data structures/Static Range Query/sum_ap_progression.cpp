/**
 *    Given an array and Q query, for each query, given L, R, consider the subarray from L to R
 *    calculate the sum of the multiplication of each number with its index(1-based) 
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

uint64_t random_address() { char *p = new char; delete p; return uint64_t(p); }

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

int32_t main(){
    int N = 100;
    int A_MAX = 10000;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        a[i] = rng() % A_MAX;
        cout<<a[i]<<(i < N - 1 ? ' ' : '\n');
    }
    vector<int> pref(N), prefA(N);
    prefA[0] = 1 * a[0];
    pref[0] = a[0];
    for(int i = 1; i < N; i++){
        pref[i] = pref[i - 1] + a[i];
        prefA[i] = prefA[i - 1] + (i + 1) * a[i];
    }
    auto getSum = [&](int l, int r){
        return (pref[r] - (l == 0 ? 0 : pref[l - 1]));
    };
    auto getSumA = [&](int l, int r){
        return (prefA[r] - (l == 0 ? 0 : prefA[l - 1]));
    };
    auto get = [&](int l, int r){
        if(l == 0){
            return prefA[r];
        }
        int right = getSumA(0, r);
        int left = getSumA(0, l - 1);
        int sum = getSum(l, r);
        return right - left - l * sum;
    };
    int Q = 100000;
    while(Q--){
        int l = rng() % N;
        int r = rng() % N;
        if(l > r){
            swap(l, r);
        }
        assert(l >= 0 && l < N);
        assert(r >= 0 && r < N);
        int mul = 1, brute = 0;
        for(int i = l; i <= r; i++){
            brute += mul * a[i];
            mul++;
        }
        assert(get(l, r) == brute);
    }
    return 0;
}
