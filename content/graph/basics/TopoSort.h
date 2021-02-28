/**
 * Description: sorts vertices such that if there exists an edge x->y, then x goes before y
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/quantumsuperposition
 */

struct TopoSort {
	int N; vector<int> in, res;
	vector<vector<int>> adj;
	void init(int _N) { N = _N; in.resize(N); adj.resize(N); }
	void ae(int x, int y) { adj[x].push_back(y), in[y] ++; }
	bool sort() {
		queue<int> todo;
		for(int i = 0; i < N; i++) if (!in[i]) todo.push(i);
		while (sz(todo)) {
			int x = todo.front(); todo.pop(); res.push_back(x);
			each(i,adj[x]) if (!(--in[i])) todo.push(i);
		}
		return sz(res) == N;
	}
};