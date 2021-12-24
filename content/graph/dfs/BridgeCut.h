/**
 * Description: Tarjan algorithm finding articulation points and bridges
 * Time: O(N+M)
 * Usage: BridgeCut tree(n);
 * tree.ae(u, v);
 * tree.solve();
 * tree.bridges, tree.cuts
 * Verification: https://leetcode.com/problems/critical-connections-in-a-network/
 */
struct BridgeCut {
    vector<int> low, num, parent;
    vector<bool> articulation;
    int counter, root, children;
    vector<pair<int,int>> bridges; vector<int> cuts;
    int V; vector<vector<int>> G;
    BridgeCut(int _V): G(_V), V(_V), num(_V, -1), low(_V, 0), parent(_V, 0), articulation(_V, false){}
    void ae(int u,int v){ G[u].push_back(v); G[v].push_back(u); }
    void solve() {
        for(int i = 0; i < V; i++) if (num[i] == -1) {
            root = i; children = 0;
            dfs(i);
            articulation[root] = (children > 1);
        }
        for(int i = 0; i < V; i++) if (articulation[i]) cuts.push_back(i);
    }
private:
    void dfs(int u) {
        low[u] = num[u] = counter++;
        for(int j = 0; j < (int)G[u].size(); j++){
            int v = G[u][j];
            if (num[v] == -1) {
                parent[v] = u;
                if (u == root) children++;
                dfs(v);
                if (low[v] >= num[u])
                    articulation[u] = true;
                if (low[v] > num[u]) bridges.push_back(make_pair(u, v));
                low[u] = min(low[u], low[v]);
            } else if (v != parent[u])
                low[u] = min(low[u], num[v]);
        }
    }
};