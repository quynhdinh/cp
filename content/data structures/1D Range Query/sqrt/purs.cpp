#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n, q; cin>>n>>q;
	int B = sqrt(n);
	vector<int> a(n);
	vector<long long> sum(n / B + 1);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum[i / B] += a[i];
	}
	for(int rep = 0; rep < q; rep++) {
		int type; cin>>type;
		if (type == 1) {
			int i, x; cin>>i>>x;
			i--;
			sum[i / B] += x - a[i];
			a[i] = x;
		} else {
			assert(type == 2);
			int L, R; cin>>L>>R;
			L--;
			R--;
			long long res = 0;
			for (int i = L; i / B == L / B && i <= R; i++){ // O(B)
				res += a[i];
			}
			for (int i = L / B + 1; i <= R / B - 1; i++) res += sum[i]; // O(N / B)
			if (L / B != R / B) {
				// int start = R / B * B;
				// for(int i = R; i >= start; i--) res += a[i];
				for(int i = R; i / B == R / B; i--) res += a[i]; // O(B)
			}
			cout<<res<<'\n';
		}
	}
	return 0;
}
