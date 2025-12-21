#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
long long f_size[100005], f_out[100005], f_in[100005];
bool check[100005];
void dfs_size(int u, int par) {
  if (check[u] == true)
    f_size[u] = 1; 
  for (auto v: adj[u]) {
    if (v == par) continue;
    dfs_size(v, u); 
    f_size[u] += f_size[v]; 
  }
}
// f_size[u]: the number of marked nodes in the subtree of u
void dfs_out(int u, int par) {
  for (auto v: adj[u]) {
    if (v == par) continue;
    dfs_out(v, u); 
    f_out[u] += f_out[v] + f_size[v]; 
  }
}
// f_out[u]: the sum of distances from u to all marked nodes in the subtree of u
void dfs_in(int u, int par) {
  for (auto v: adj[u]) {
    if (v == par) continue;
    f_in[v] = f_in[u] + f_out[u] - f_out[v] - f_size[v] + f_size[0] - f_size[v]; 
    dfs_in(v, u); 
  }
}
// f_in[u]: the sum of distances from u to all marked nodes not in the subtree of u
// In details:
// We are doing top down here. When we go from u to v, we need to update f_in[v].
// f_in[v] will have the following components:
// 1. f_in[u]: the sum of distances from u to all marked nodes not in the subtree of u
// 2. f_out[u]: the sum of distances from u to all marked nodes in the subtree of u
// 3. - f_out[v] - f_size[v]: we remove the contribution of the subtree of v
// 4. + f_size[0] - f_size[v]: we add the contribution of the marked nodes not in the subtree of v
int main(){
  // the answer for each node u is f_in[u] + f_out[u]
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < k; i++) {
    int x; cin >> x; x--;
    check[x] = true;
  }
  dfs_size(0, -1);
  dfs_out(0, -1);
  dfs_in(0, -1);
  for (int i = 0; i < n; i++) {
    cout << f_in[i] + f_out[i] << '\n';
  }
  return 0;
}