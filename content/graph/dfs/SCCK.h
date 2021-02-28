/**
 * Description: Kosaraju's Algorithm, DFS twice to generate 
 	* strongly connected components in topological order. $a,b$
 	* in same component if both $a\to b$ and $b\to a$ exist.
 * Time: O(N+M)
 * Source: Wikipedia
 * Verification: POI 8 peaceful commission
 */

struct SCC {
	int N; vector<vector<int>> adj, radj;
	vector<int> todo, comp, comps; vector<bool> vis;
	void init(int _N) { N = _N;
		adj.resize(N), radj.resize(N), comp = vector<int>(N,-1), vis.resize(N); }
	void ae(int x, int y) { adj[x].push_back(y), radj[y].push_back(x); } // add edge
	void dfs(int x) {
		vis[x] = 1; for(auto& y: adj[x]) if (!vis[y]) dfs(y);
		todo.push_back(x); }
	void dfs2(int x, int v) {
		comp[x] = v;
		for(auto y: radj[x]) if (comp[y] == -1) dfs2(y,v); }
	void gen() { // fills allComp
	    for(int i = 0; i < N; i++) if (!vis[i]) dfs(i);
		reverse(todo.begin(), todo.end());
		for(auto& x: todo) if (comp[x] == -1) dfs2(x, x), comps.push_back(x);
	}
};