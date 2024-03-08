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

#define int long long

int32_t main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int& x: a){
        cin>>x;
    }
    vector<int> pref(n), prefA(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    prefA[0] = 1 * a[0];
    for(int i = 1; i < n; i++){
        prefA[i] = prefA[i - 1] + (i + 1) * a[i];
    }
    auto getSum = [&](int l, int r){
        return (pref[r] - (l == 0 ? 0 : pref[l - 1]));
    };
    auto getSumA = [&](int l, int r){
        return (prefA[r] - (l == 0 ? 0 : prefA[l - 1]));
    };
    auto get = [&](int l, int r){
        int right = getSumA(0, r);
        int left = getSumA(0, l - 1);
        int sum = getSum(l, r);
        return right - left - l * sum;
    };
    int Q; cin>>Q;
    while(Q--){
        int l, r; cin>>l>>r;
        int mul = 1, res = 0;
        for(int i = l; i <= r; i++){
            res += mul * a[i];
            mul++;
        }
        cout<<get(l, r)<<' '<<res<<'\n';
    }
    return 0;
}

