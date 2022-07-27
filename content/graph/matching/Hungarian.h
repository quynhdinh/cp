/**
 * Description: Given array of (possibly negative) costs to complete
	* each of $N$ (1-indexed) jobs w/ each of $M$ workers $(N\le M)$,
	* finds min cost to complete all jobs such that each worker is
	* assigned to at most one job. Dijkstra with potentials works
	* in almost the same way as MCMF.
 * Time: O(N^2M)
 * Source: https://github.com/mpfeifer1/Kattis/blob/master/cordonbleu.cpp, tourist?
	* http://www.hungarianalgorithm.com/examplehungarianalgorithm.php
	* https://en.wikipedia.org/wiki/Hungarian_algorithm
	* https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/
	* https://brilliant.org/wiki/hungarian-matching/
	* https://www.topcoder.com/community/competitive-programming/tutorials/assignment-problem-and-hungarian-algorithm/
 * Verification: https://www.spoj.com/problems/BABY/
 	* https://open.kattis.com/problems/cordonbleu
	* also see https://codeforces.com/blog/entry/63701
 */
template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
using C = ll;
C hungarian(const vector<vector<C>>& a) {
	int N = sz(a)-1, M = sz(a[0])-1; assert(N <= M);
	vector<C> u(N+1), v(M+1); // potentials to make edge weights >= 0
	vi job(M+1);
	FOR(i,1,N+1) { // find alternating path with job i
		const C inf = numeric_limits<C>::max();
		int w = 0; job[w] = i; // add "dummy" 0, find path to real worker
		vector<C> dist(M+1,inf); vi pre(M+1,-1); vector<bool> done(M+1);
		while (job[w]) { // 
			done[w] = 1; int j = job[w], nexW; C delta = inf;
			// fix dist[j], update dists from j
			F0R(W,M+1) if (!done[W]) { // try all workers
				if (ckmin(dist[W],a[j][W]-u[j]-v[W])) pre[W] = w;
				if (ckmin(delta,dist[W])) nexW = W;
			}
			F0R(W,M+1) { // subtract constant from all edges going
				// from done -> not done vertices, lowers all
				// remaining dists by constant
				if (done[W]) u[job[W]] += delta, v[W] -= delta;
				else dist[W] -= delta;
			}
			w = nexW;
		} // potentials adjusted so all edge weights >= 0
		for (int W; w; w = W) job[w] = job[W = pre[w]];
	} // job[w] = 0, found alternating path
	return -v[0]; // min cost
}
