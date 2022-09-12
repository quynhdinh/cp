// Verification: https://atcoder.jp/contests/dp/tasks/dp_g
// Author: me
struct LongestPathDAG {
    vector<vector<int>> edges;
    vector<int> in_degree, dist, _trace, path;
    vector<bool> visited;
    int n, length;
    LongestPathDAG(int _n) {
        n = _n;
        edges.resize(n), dist.resize(n), in_degree.resize(n), _trace.resize(n);
        visited.resize(n, false);
        iota(_trace.begin(), _trace.end(), 0);
        length = 0;
    }
    void ae(int x, int y) {  edges[x].push_back(y), in_degree[y]++; }
    void solve(){
        for(int i = 0; i < n; i++)
            if(!visited[i] && in_degree[i] == 0)
                dfs(i);
        int en = 0;
        for(int i = 0; i < n; i++)
            if(dist[i] > length){
                en = i;
                length = dist[i];
            }
        while(en != _trace[en]){
            path.push_back(en);
            en = _trace[en];
        }
        path.push_back(en);
        reverse(path.begin(), path.end());
    }
    void dfs(int a){
        visited[a] = true;
        for(int& b: edges[a]){
            if(dist[b] < dist[a] + 1){
                dist[b] = dist[a] + 1;
                _trace[b] = a;
            }
            --in_degree[b];
            if(in_degree[b] == 0)
                dfs(b);
        }
    }
};