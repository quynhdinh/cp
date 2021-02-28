/**
 * Description: Tarjan's, DFS once to generate
 	* strongly connected components in topological order. $a,b$
 	* in same component if both $a\to b$ and $b\to a$ exist.
 	* Uses less memory than Kosaraju b/c doesn't store reverse edges.
 * Time: O(N+M)
 * Source: KACTL
 	* https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/SCC.h
 * Verification: https://cses.fi/problemset/task/1686/
 */
template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
struct SCC {
	int N, ti = 0; vector<vector<int>> adj;
	vector<int> disc, comp, st, comps;
	void init(int _N) { N = _N; adj.resize(N), disc.resize(N), comp = vector<int>(N,-1); }
	void ae(int x, int y) { adj[x].push_back(y); } // add edge
	int dfs(int x) {
		int low = disc[x] = ++ti; st.push_back(x); // disc[y] != 0 -> in stack
		for(auto& y: adj[x]) if (comp[y] == -1) ckmin(low,disc[y]?:dfs(y));
		if (low == disc[x]) { // make new SCC, pop off stack until you find x
			comps.push_back(x); for (int y = -1; y != x;)
				comp[y = st.back()] = x, st.pop_back();
		}
		return low;
	}
	void gen() {
	    for(int i = 0; i < N; i++) if (!disc[i]) dfs(i);
		reverse(comps.begin(), comps.end());
	}
};