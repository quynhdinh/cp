#include <bits/stdc++.h>
using namespace std;

// program to print the cycle of a no multi edge graph having n vertices n edges
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        int u, v; cin>>u>>v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> stack;
    vector<int> cycle;
    vector<bool> visited(N, false);
    function<bool(int, int)> dfs = [&](int node, int parent){
        if(visited[node]){
            cycle = {node};
            while(stack.back() != node){
                cycle.push_back(stack.back());
                stack.pop_back();
            }
            return true;
        }
        stack.push_back(node);
        visited[node] = true;
        for(int neigh: G[node])
            if(neigh != parent && dfs(neigh, node))
                return true;
        stack.pop_back();
        return false;
    };
    dfs(0, -1);
    for(int x: cycle){
        cout<<x<<' ';
    }
    set<array<int, 2>> cycle_edges;
    int C = cycle.size();
    for(int i = 0; i < C; i++){
        int a = cycle[i], b = cycle[(i + N) % C];
        cycle_edges.insert({a, b});
        cycle_edges.insert({b, a});
    }
    return 0;
}
