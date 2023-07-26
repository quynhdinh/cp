/**
 * Description: Calculates least common ancestor in tree with verts 
 	* $0..N-1$ and root $R$ using binary jumping. 
 * Time: O(N\log N) build, O(\log N) query
 * Memory: O(N\log N)
 * Source: USACO Camp, KACTL
 * Verification: https://www.spoj.com/problems/LCA/
 * Usage: LCA tree; tree.init(N); tree.lca(a, b); tree.gen();
 */

struct LCA {
	int N; vector<vector<int>> par, adj; vector<int> depth;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) ++d;
		par.assign(d,vector<int>(N)); adj.resize(N); depth.resize(N);
	}
	void ae(int x, int y) { adj[x].push_back(y), adj[y].push_back(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		for(int i=1;i<(int)par.size();i++) par[i][x] = par[i-1][par[i-1][x]];
		for(auto &y: adj[x]) if (y != par[0][x])
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		for(int i=0;i<(int)par.size();i++) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		for(int i=(int)par.size()-1;i>= 0;i--){
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { // # edges on path
		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};
