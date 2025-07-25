// Given a tree, every vertex has color. Query is how many vertices in subtree of vertex v are colored with color c?
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
vector<vector<int>> g;
vector<int> col;
// naive O(N^2)
int cnt[maxn];
void add(int v, int p, int x){
    cnt[col[v]] += x;
    for(auto u: g[v])
        if(u != p)
            add(u, v, x);
}
void dfs(int v, int p){
    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    add(v, p, -1);
    for(auto u : g[v])
        if(u != p)
            dfs(u, v);
}

int main(){
    int n; cin>>n;
    g.resize(n);
    col.resize(n);
    return 0;
}