/**
 * Source: KACTL
 * Time: O(N)
 * Description: f[i] is length of the longest proper suffix
 	* of the i-th prefix of s that is a prefix of s
 * Verification: https://open.kattis.com/problems/stringmatching
 */

vector<int> kmp(string s) {
	int N = s.size(); vector<int> f(N+1); f[0] = -1;
	for(int i = 1; i <= N; i++){
		for (f[i]=f[i-1];f[i]!=-1&&s[f[i]]!=s[i-1];)
            f[i]=f[f[i]];
            f[i]++;
        }
	return f;
}
vector<int> getOc(string a, string b) { // find occurrences of a in b
	vector<int> f = kmp(a+"@"+b), ret;
	int n = a.size();
	int m = b.size();
	for(int i = n; i < m + 1; i++)
        if (f[i+n+1] == n)
            ret.push_back(i-n);
	return ret;
}