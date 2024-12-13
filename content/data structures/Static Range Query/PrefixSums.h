/**
 * Description: calculates rectangle sums in constant time
 * Source: KACTL
 * Verification: POI 16 Ticket Inspector
 */
template<class T> struct Prefix1D {
	vector<T> pref;
	void init(const vector<T>& v){
		pref = v;
		partial_sum(begin(pref), end(pref), begin(pref));
	}
	T get(int left, int right) {
		return (pref[right] - (left == 0 ? 0 : pref[left - 1]));
	}
};

template<class T> struct PrefixSums {
	vector<vector<T>> sum;
	void init(const vector<vector<T>>& v) {
		int R = v.size(), C = v[0].size();
		sum.assign(R+1,vector<T>(C+1));
		for(int i = 0; i < R; i++)  for(int j = 0; j < C; j++)
			sum[i+1][j+1] = v[i][j]+sum[i+1][j]+sum[i][j+1]-sum[i][j];
	}
	T get(int r1, int c1, int r2, int c2){
		r2++, c2++;
		return sum[r2][c2]-sum[r1][c2]-sum[r2][c1]+sum[r1][c1];
	}
};

template<class T> struct PrefixSums {
	vector<vector<T>> sum;
	void init(const vector<vector<T>>& v) {
		int R = v.size(), C = v[0].size();
		sum.assign(R, vector<T>(C));
		for(int r = 0; r < R; r++)
			for(int c = 0; c < C; c++)
				sum[r][c] = v[r][c] + (r - 1 >= 0 ? sum[r - 1][c] : 0)
				- (r - 1 >= 0 && c - 1 >= 0 ? sum[r - 1][c - 1] : 0)
				+ (c >= 1 ? sum[r][c - 1] : 0);
	}
	T get(int r1, int c1, int r2, int c2){
		return sum[r2][c2] 
			+ (r1 - 1 >= 0 && c1 - 1 >= 0 ? sum[r1 - 1][c1 - 1] : 0) 
			- (c1 - 1 >= 0 ? sum[r2][c1 - 1] : 0) 
			- (r1 - 1 >= 0 ? sum[r1 - 1][c2] : 0);
	}
};

PrefixSums<int> pref;
pref.init(a);
pref.get(r1, c1, r2, c2);

// PrefixSumsString table;
// table.init(s);
// table.query(0, n - 1, 'a')

struct PrefixSumsString {
	vector<vector<int>> prefix;
	void init(const string& s){
		int n = (int)s.size();
		prefix.resize(26, vector<int>(n));
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < n; j++)
				prefix[s[j] - 'a'][j] = 1;
		for(auto& row: prefix)
			partial_sum(begin(row), end(row), begin(row));
	}
	int query(int l, int r, int pos){
		return (l == 0 ? prefix[pos][r] : prefix[pos][r] - prefix[pos][l - 1]);
	}
};

template<class T> struct PrefixBit {
	vector<vector<T>> pref;
	const int BASE = 30; // 1e9
	void init(const vector<T>& v){
		const int n = size(v);
		pref.assign(BASE, vector<int>(n));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < BASE; j++)
				if((1 << j) & v[i])
					pref[j][i] = 1;
		for(int i = 0; i < BASE; i++)
			partial_sum(begin(pref[i]), end(pref[i]), begin(pref[i]));
	}
	T get_or(int l, int r){
		T or_value = 0;
		for(int bit = 0; bit < BASE; bit++){
			int cnt = pref[bit][r] - (l == 0 ? 0 : pref[bit][l - 1]);
			if(cnt > 0)
				or_value += (1 << bit);
		}
		return or_value;
	}
	T get_and(int l, int r){
		T and_value = 0;
		for(int bit = 0; bit < BASE; bit++){
			int cnt = pref[bit][r] - (l == 0 ? 0 : pref[bit][l - 1]);
			if(cnt == r - l + 1)
				and_value += (1 << bit);
		}
		return and_value;
	}
	T get_xor(int l, int r){
		T xor_value = 0;
		for(int bit = 0; bit < BASE; bit++){
			T cntOne = pref[bit][r] - (l == 0 ? 0 : pref[bit][l - 1]);
			if(cntOne & 1)
				xor_value += (1 << bit);
		}
		return xor_value;
	}
};