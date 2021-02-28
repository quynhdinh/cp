/**
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity.
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
/**
template<class T> T kruskal(int N, vector<pair<T,pair<int, int>>> ed) {
	sort(ed.begin(), ed.end());
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	for(auto& a: ed) if (D.unite(a.second.first,a.second.second)) ans += a.first;
	return ans;
} */