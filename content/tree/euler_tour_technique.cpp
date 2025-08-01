#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

int main(){
  int n; cin>>n;
  vector<int> in(n), out(n), tour(n), subtree_size(n);
  vector<vector<int>> g(n);
  int timer = 0;
  for (int i = 0; i < n - 1; ++i){
    int u, v; cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int label = 0;
  function<void(int, int)> dfs = [&](int u, int parent){
    in[u] = timer++;
    tour[u] = label++;
    subtree_size[u] = 1;
    for (auto v : g[u]){
      if(v == parent) continue;
      dfs(v, u);
      subtree_size[u] += subtree_size[v];
    }
    out[u] = timer - 1;
  };
  auto isInSubtree = [&](int u, int v){
    return in[u] <= in[v] && out[v] <= out[u];
  };
  // [in[u]..out[u]]: all the values in subtree of u
  dfs(0, -1);
  for(int i = 0; i < n; i++){
    debug(i, in[i], out[i]);
  }
  for(int i = 0; i < n ; i++){
    assert(in[i] < n && out[i] < n);
  }
  for(int i = 0; i < n ; i++){
    assert(tour[i] == in[i]);
  }
  debug(tour);
  debug(subtree_size);
  // int u, v;
  // cin >> u >> v; // query: is v in subtree of u?
  // if (isInSubtree(u, v))
  //   cout << "Yes\n";
  // else
  //   cout << "No\n";

  return 0;
}