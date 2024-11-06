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

PrefixSums<int> pref;
pref.init(a);
pref.get(r1, c1, r2, c2);

// PrefixSumsString table;
// table.init(s);
// table.query(0, n - 1, 'a')
// table.queryByChar(0, (int)s.size() - 1, 'Q');

struct PrefixSumsString {
	vector<vector<int>> prefix;
	int getPos(char c){
		bool isUpperCase = (c == toupper(c));
		return (c  - (isUpperCase ? 'A' : 'a'));
	}		
	void init(const string& s){ // this only works with all-lowercase/all-uppercase characters
		int n = (int)s.size();
		prefix.resize(26, vector<int>(n));
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < n; j++){
				int id = getPos(s[j]);
				prefix[id][j] = 1;
			}
		}
		for(int i = 0; i < 26; i++){
			for(int j = 1; j < n; j++){
				prefix[i][j] = prefix[i][j] + prefix[i][j - 1];
			}
		}
	}
	int query(int l, int r, int pos){
		return (l == 0 ? prefix[pos][r] : prefix[pos][r] - prefix[pos][l - 1]);
	}
	int query(int l, int r, char ch){
		int pos = getPos(ch);
		return query(l, r, pos);
	}
};
