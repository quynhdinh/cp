/*
 * Description: Calculates longest path in tree.
 * Source: Benq
 * Verification:
   * http://www.spoj.com/problems/PT07Z/ (obvious)
   * https://leetcode.com/problems/minimum-height-trees
   * https://codeforces.com/contest/1182/problem/D
 */
/*
 * input: size and adding edges
 * output: diameter in length, center(vertice(s))
 * */
template<int SZ> struct TreeDiameter {
	int N, par[SZ], dist[SZ], diaLen;
	vector<int> adj[SZ], dia, center;
	void ae(int a, int b) { adj[a].push_back(b), adj[b].push_back(a); }
	void dfs(int x) {
		for(auto& y: adj[x]) if (y != par[x]) {
			par[y] = x; dist[y] = dist[x]+1;
			dfs(y); }
	}
	void genDist(int x) { par[x] = -1; dist[x] = 0; dfs(x); }
	void init(int _N) {
		N = _N; dia = {0,0};
		genDist(0); for(int i = 0; i < N; i++) if (dist[i]>dist[dia[0]]) dia[0] = i;
		genDist(dia[0]); for(int i = 0; i < N; i++) if (dist[i]>dist[dia[1]]) dia[1] = i;
		diaLen = dist[dia[1]];
		int cen = dia[1]; for(int i = 0; i < diaLen/2; i++)cen = par[cen];
		center = {cen}; if (diaLen&1) center.push_back(par[cen]);
	}
};
/*
 * Description: Calculates longest path in tree and its path.
 * Source: https://github.com/ngthanhtrung23/ACM_Notebook_new/blob/master/Graph/tree_diameter.h
 * Verification:
   * https://judge.yosupo.jp/problem/tree_diameter
 */
/*
 * Usage: auto [dist, path] = get_diameter(g);
 * */

pair<long long, vector<int>> get_diameter(const vector<vector<pair<int, int>>> &g) {
    int n = g.size();
    vector<long long> dist(n);
    vector<int> parent(n);

    function<void(int, int, long long)> dfs = [&](int u, int fu, long long cur_dist) {
        dist[u] = cur_dist;
        parent[u] = fu;
        for (auto [v, cost]: g[u])
            if (v != fu) {
                dfs(v, u, cur_dist + cost);
            }
    };
    dfs(0, -1, 0);
    // r = furthest node from root
    int r = max_element(dist.begin(), dist.end()) - dist.begin();
    dfs(r, -1, 0);
    // r->s = longest path
    int s = max_element(dist.begin(), dist.end()) - dist.begin();

    vector<int> path;
    for (int x = s; x >= 0; x = parent[x]) path.push_back(x);

    return {dist[s], path};
}