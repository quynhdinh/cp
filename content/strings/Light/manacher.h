/**
 * Source: http://codeforces.com/blog/entry/12143
 * Time: O(N)
 * Description: length of largest palindrome centered at each character of string
 	* and between every consecutive pair
 * Verification: http://www.spoj.com/problems/MSUBSTR/
 */

vi manacher(str s) {
	str s1 = "@"; each(c,s) s1 += c, s1 += "#";
	s1.back() = '&';
	vi ans(sz(s1)-1); int lo = 0, hi = 0;
	for(int i = 1; i < sz(s1) -1; i++){
		if (i != 1) ans[i] = min(hi-i,ans[hi-i+lo]);
		while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i] ++;
		if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
	}
	ans.erase(begin(ans));
	for(int i = 0; i < sz(ans); i++) if ((i&1) == (ans[i]&1)) ans[i] ++;
	return ans;
}
/// Usage: ps(manacher("abacaba"))