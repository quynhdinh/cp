#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
// get the longest path starting from the root
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<pair<int, int>> euler_tour;
  map<int, vector<int>> indices;
  function<void(int, int, int)> tour = [&](int u, int par, int level) {
    euler_tour.emplace_back(u, level);
    for (auto v : g[u]) {
      if (v == par) continue;
      tour(v, u, level + 1);
    }
    euler_tour.emplace_back(u, level);
  };
  tour(0, -1, 0);
  int n = euler_tour.size();
  for (int i = 0; i < n; ++i) indices[euler_tour[i].first].push_back(i);
  vector<int> prefix_max(n), suffix_max(n);
  for (int i = 0; i < n; ++i)
    if (i == 0)
      prefix_max[i] = euler_tour[i].second;
    else
      prefix_max[i] = max(prefix_max[i - 1], euler_tour[i].second);
  for (int i = n - 1; i >= 0; --i)
    if (i == n - 1)
      suffix_max[i] = euler_tour[i].second;
    else
      suffix_max[i] = max(suffix_max[i + 1], euler_tour[i].second);
  vector<int> result;
  int q; cin >> q;
  while (q--) {
    int query; cin >> query;
    const vector<int>& idx = indices[query];
    int start = idx[0], end = idx[1];
    int left = (start > 0) ? prefix_max[start - 1] : 0;
    int right = (end + 1 < n) ? suffix_max[end + 1] : 0;
    int ans = max(left, right);
    debug(query, ans);
  }
  return 0;
}