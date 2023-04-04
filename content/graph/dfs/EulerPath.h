/**
 * Description: Eulerian path starting at src if it exists, 
     * visits all edges exactly once. Works for both directed and 
     * undirected. Returns vector of {vertex,label of edge to vertex}.
     * The second element of the first pair is always $-1$.
     // The path is the first element of every pair
 * Time: O(N+M)
 * Source: USACO Training, MIT ICPC Notebook
 * Verification:
    * directed -> https://open.kattis.com/problems/eulerianpath
    * undirected -> USACO Training 3.3, Riding the Fences, https://cses.fi/problemset/task/1691
 */

template<bool directed> struct Euler {
    int N; vector<vector<pair<int,int>>> adj; vector<vector<pair<int,int>>::iterator> its; vector<bool> used;
    void init(int _N) { N = _N; adj.resize(N); }
    void ae(int a, int b) {
        int M = used.size(); used.push_back(0);
        adj[a].emplace_back(b,M); if (!directed) adj[b].emplace_back(a,M); }
    vector<pair<int,int>> solve(int src = 0) {
        its.resize(N); for(int i = 0; i < N; i++) its[i] = begin(adj[i]);
        vector<pair<int,int>> ans, s{{src,-1}}; // {{vert,prev vert},edge label}
        int lst = -1; // ans generated in reverse order
        while (!s.empty()) {
            int x = s.back().first; auto& it=its[x], en=end(adj[x]);
            while (it != en && used[it->second]) ++it;
            if (it == en) { // no more edges out of vertex
                if (lst != -1 && lst != x) return {};
                // not a path, no tour exists
                ans.push_back(s.back()); s.pop_back(); if (s.size()) lst=s.back().first;
            } else s.push_back(*it), used[it->second] = 1;
        } // must use all edges
        if (ans.size() != used.size() +1) return {};
        reverse(ans.begin(), ans.end()); return ans;
    }
};
// https://leetcode.com/problems/valid-arrangement-of-pairs/