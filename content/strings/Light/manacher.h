/**
 * Source: http://codeforces.com/blog/entry/12143
 * Time: O(N)
 * Description: length of largest palindrome centered at each character of string
 	* and between every consecutive pair
 * Verification: http://www.spoj.com/problems/MSUBSTR/
 */

vector<int> manacher(string s) {
	string s1 = "@"; for(auto& c: s) s1 += c, s1 += "#";
	s1.back() = '&';
	vector<int> ans((int)s1.size()-1); int lo = 0, hi = 0;
	for(int i = 1; i < (int)s1.size() -1; i++){
		if (i != 1) ans[i] = min(hi-i,ans[hi-i+lo]);
		while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i] ++;
		if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
	}
	ans.erase(begin(ans));
	for(int i = 0; i < (int)ans.size(); i++) if ((i&1) == (ans[i]&1)) ans[i] ++;
	return ans;
}
// Usage: vector<int> temp = manacher("abacaba");
// for(int i = 0; i < size(s); i++){
//     assert(temp[i * 2] % 2 == 1);
//     int left = i - temp[i * 2] / 2;
//     int right = i + temp[i * 2] / 2;
//     if(i + 1 < size(s)){
//         assert(temp[2 * i + 1] % 2 == 0);
//         left = i + 1 - temp[2 * i + 1] / 2;
//         right = i + temp[2 * i + 1] / 2;
//     }
// }
