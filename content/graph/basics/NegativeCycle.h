/**
 * Description: use Bellman-Ford (make sure no underflow)
 * Source: https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
 * Verification: https://cses.fi/problemset/task/1197/
 */
template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)

vector<int> negCyc(int n, vector<pair<pair<int, int>,int>> ed) { // edge and weigh
	vector<long long> d(n); vector<int> p(n); int x = -1;
	for(int i = 0; i < n; i++){
		x = -1; for(auto& t: ed) if (ckmin(d[t.first.second],d[t.first.first]+t.second))
			p[t.first.second] = t.first.first, x = t.first.second;
		if (x == -1) return {};
	}
	for(int i = 0; i < n; i++) x = p[x]; // enter cycle
	vector<int> cyc = {x}; while (p[cyc.back()] != x) cyc.push_back(p[cyc.back()]);
	reverse(cyc.begin(), cyc.end()); return cyc;
}
/**
Explanation:
If we follow the links back from t.f.s then we must always enter a cycle.
Otherwise, this would contradict the assumption that there exists a shorter
path to t.f.s when considering paths of arbitrary length than those of
length at most n-1. The sum of the edge weights along this path is
non-positive, and it can't be zero because then it would have no origin ...
*/