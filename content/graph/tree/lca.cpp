/**
 * Description: Find the lowest common ancestor in a DAG.
 * Source: Errichto
 * Verification:
   * https://www.spoj.com/problems/LCA/
 */

#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr << #a << ": " << a << endl
const int MAX_N = 1000;
const int LOG = 10;
vector<int> edges[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];
void dfs(int a, int par){
    for(int b: edges[a]){
        if(b == par){
            continue;
        }
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for(int i = 1; i < LOG; i++){
            up[b][i] = up[up[b][i-1]][i - 1];
        }
        dfs(b, a);
    }
}

 
int get_lca(int a, int b){ //O(log(n))
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    //1. move one of them to the same depth
    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--){
        if(k & (1 << j)){
            a = up[a][j];
        }
    }
    //2. if b is the ancestor of a then return b
    if(a == b) return a;
    //3. move until they met.
    for(int j = LOG - 1; j >= 0; j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
//get the distance between two nodes
//TODO: test this function
int get_dist(int a, int b){ //O(logN)
	return depth[a] + depth[b] - 2 * depth(get_lca(a, b));
}
void test_case(){
    int V; cin>>V;
    for(int i = 0; i < V; i++){
        edges[i].clear();
    }
    memset(up, sizeof up, 0);
    for(int i = 0; i < V; i++){
        int no_children; cin>>no_children;
        for(int j = 0; j < no_children; j++){
            int adj;
            cin>>adj;
            adj--;
            edges[i].push_back(adj);
            edges[adj].push_back(i);
        }
    }
    dfs(0, -1);
    int q; cin>>q;
    while(q--){
        int a, b; cin>>a>>b;
        a--; b--;
        cout<<get_lca(a, b) + 1<<'\n';
    }
}
int32_t main() {
    int tt; cin>>tt;
    for(int t_case = 1; t_case <= tt; t_case++){
        cout<<"Case "<<t_case<<":\n";
        test_case();
    }
}
