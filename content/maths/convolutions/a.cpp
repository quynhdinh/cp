/**
 *    created: 26.05.2024_14:11:24
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

#define int long long

template<bool do_superset, bool do_inverse, typename T>
vector<T> sum_over_subsets(vector<T> arr) {
    const size_t n = arr.size();
    for (size_t b = 1; b < n; b <<= 1) {
        if constexpr(do_inverse) {
            if constexpr(do_superset) {
                for (size_t i = n - b - 1; i; --i) {
                    if (~i & b) arr[i] -= arr[i ^ b];
                }
                arr[0] -= arr[b];
            } else {
                for (size_t i = n - 1; i; --i) {
                    if (i & b) arr[i] -= arr[i ^ b];
                }
            }
        } else {
            for (size_t st = do_superset ? 0 : b; st < n; st += b << 1) {
                const size_t thr = do_superset ? min(st + b, n - b) : st + b;
                for (size_t i = st; i < thr; ++i) {
                    arr[i] += arr[i ^ b];
                }
            }
        }
    }
    return arr;
}
//res[k] = sum({arr1[i] * arr2[j] | (i | j) == k})
//O(nlog(n))
template<typename T>
vector<T> or_convolution(vector<T> arr1, vector<T> arr2) {
    const size_t m = max(arr1.size(), arr2.size());
    const size_t n = m & (m - 1) ? 2 << __lg(m) : m;
    arr1.resize(n, (T)0);
    arr2.resize(n, (T)0);
    arr1 = sum_over_subsets<0, 0>(arr1);
    arr2 = sum_over_subsets<0, 0>(arr2);
    for (size_t i = 0; i < n; ++i) arr1[i] *= arr2[i];
    arr1 = sum_over_subsets<0, 1>(arr1);
    return arr1;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {6, 7, 8, 9, 10};
    map<int, int> brute;
    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b.size(); j++){
            int orValue = i | j;
            brute[orValue] += a[i] * b[j];
        }
    }
    vector<int> res = or_convolution<int>(a, b);
    for(int i = 0; i < (int)res.size(); i++){
        assert(res[i] == brute[i]);
    }
    return 0;
}
