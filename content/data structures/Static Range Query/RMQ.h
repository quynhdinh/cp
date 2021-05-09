/**
 * Description: 1D range minimum query. Can also do queries
 	* for any associative operation in $O(1)$ with D\&C
 * Source: KACTL
 * Verification:
	* https://cses.fi/problemset/stats/1647/
	* http://wcipeg.com/problem/ioi1223
	* https://pastebin.com/ChpniVZL
 * Memory: O(N\log N)
 * Time: O(1)
 */

template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); }
	vector<T> v; vector<vector<int>> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); }
	void init(const vector<T>& _v) {
		v = _v; jmp = {vector<int>(v.size())}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= v.size(); ++j) {
			jmp.pb(vector<int>(v.size()-(1<<j)+1));
			for(int i = 0; i < jmp[j].size(); i++) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		assert(l <= r); int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};