/**
 * Description: A line of cow with heights, with each query you have
 * to output the difference of the tallest and the shortest cow.
 * Source: KACTL
 * Verification:
	* https://oj.vnoi.info/problem/nklineup
 * Memory: O(N\log N)
 * Time: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50'001;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int mx[MAX_N][LOG]; // mx[i][j] is the maximum among a[i..i+2^j-1]
int bin_log[MAX_N];

int query(int L, int R) { //find the maximum in [L..R]
	int length = R - L + 1;
	int k = bin_log[length];
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

int query2(int L, int R){//find the maximum in [L..R]
    int length = R - L + 1;
	int k = bin_log[length];
    return max(mx[L][k], mx[R-(1<<k)+1][k]);
}
int main() {
	// 1) read input
	int n, q;
	cin >> n >> q;
	bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
        mx[i][0] = a[i];
	}
	// 2) preprocessing, O(N*log(N))
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
			mx[i][k] = max(mx[i][k-1], mx[i+(1<<(k-1))][k-1]);
		}
	}
	// 3) answer queries O(1) each
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
        L--; R--;
		cout << query2(L, R) - query(L, R) << "\n";
	}
}