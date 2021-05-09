/**
 * Description: The centroid of a tree of size $N$ is a vertex such that
 	* after removing it, all resulting subtrees have size at most $\frac{N}{2}.$
 	* Supports updates in the form ``add 1 to all verts $v$ such that $dist(x,v)\le y$."
 * Time: O(N\log N) build, O(\log N) update and query
 * Memory: O(N\log N)
 * Source: Benq
 * Verification:
	* solves https://dmoj.ca/problem/dmopc19c7p6
	* https://codeforces.com/contest/342/problem/E
	* Triway Cup 2019 G
 */
template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)

void ad(vi& a, int b) { ckmin(b,sz(a)-1); if (b>=0) a[b]++; }

void prop(vi& a) { for(int i = sz(a) - 2; i >= 0; i--) a[i] += a[i+1]; }

template<int SZ> struct Centroid {
	vi adj[SZ]; void ae(int a,int b){adj[a].pb(b),adj[b].pb(a);}
	bool done[SZ]; // processed as centroid yet
	int N,sub[SZ],cen[SZ],lev[SZ]; // subtree size, centroid anc
	int dist[32-__builtin_clz(SZ)][SZ]; // dists to all ancs
	vi stor[SZ], STOR[SZ];
	void dfs(int x, int p) { sub[x] = 1;
		each(y,adj[x]) if (!done[y] && y != p)
			dfs(y,x), sub[x] += sub[y];
	}
	int centroid(int x) {
		dfs(x,-1);
		for (int sz = sub[x];;) {
			pair<int, int> mx = {0,0};
			each(y,adj[x]) if (!done[y] && sub[y] < sub[x])
				ckmax(mx,{sub[y],y});
			if (mx.first*2 <= sz) return x;
			x = mx.second;
		}
	}
	void genDist(int x, int p, int lev) {
		dist[lev][x] = dist[lev][p]+1;
		each(y,adj[x]) if (!done[y] && y != p) genDist(y,x,lev); }
	void gen(int CEN, int _x) { // CEN = centroid above x
		int x = centroid(_x); done[x] = 1; cen[x] = CEN;
		sub[x] = sub[_x]; lev[x] = (CEN == -1 ? 0 : lev[CEN]+1);
		dist[lev[x]][x] = 0;
		stor[x].rsz(sub[x]),STOR[x].rsz(sub[x]+1);
		each(y,adj[x]) if (!done[y]) genDist(y,x,lev[x]);
		each(y,adj[x]) if (!done[y]) gen(x,y);
	}
	void init(int _N) { N = _N; for(int i = 1; i < N + 1; i++) done[i] = 0;
		gen(-1,1); } // start at vert 1
	void upd(int x, int y) {
		int cur = x, pre = -1;
		for(int i = lev[x]; i >= 0; i--) {
			ad(stor[cur],y-dist[i][x]);
			if (pre != -1) ad(STOR[pre],y-dist[i][x]);
			if (i > 0) pre = cur, cur = cen[cur];
		}
	} // call propAll() after all updates
	void propAll() { for(int i = 1; i < N + 1; i++) prop(stor[i]), prop(STOR[i]); }
	int query(int x) { // get value at vertex x
		int cur = x, pre = -1, ans = 0;
		for(int i = lev[x]; i >= 0; i--)  { // if pre != -1, subtract those from
			ans += stor[cur][dist[i][x]]; // same subtree
			if (pre != -1) ans -= STOR[pre][dist[i][x]];
			if (i > 0) pre = cur, cur = cen[cur];
		}
		return ans;
	}
};