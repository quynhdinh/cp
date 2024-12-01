/**
 * Description: insert pair $(a,b)$ and query max value 
 	* of $b$ over all pairs satisfying $a\ge x$.
 * Source: bqi343
 * Verification: https://codeforces.com/gym/102059/problem/K
 	* http://www.usaco.org/index.php?page=viewproblem2&cpid=995
 * Time: O(\log N)
 */

struct MaxQuery {
	map<int,long long> m;
	void ins(int a, long long b) {
		auto it = m.lower_bound(a); if (it != end(m) && it->second >= b) return;
		it = m.insert(it,{a,b}); it->second = b;
		while (it != begin(m) && prev(it)->second <= b) m.erase(prev(it));
	}
	long long query(int x) { auto it = m.lower_bound(x); 
		return it == end(m) ? 0 : it->second; }
};