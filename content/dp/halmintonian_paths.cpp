// solution tp: https://cses.fi/problemset/task/1690/
#include <bits/stdc++.h>
#pragma GCC optimize("O3") // O3 or we time out :(
using namespace std;
const int M = 1e9 + 7;
// dp[mask][j] -> i is bitmask of what we've visited, j is current node
// transition (k is edges from j): dp[i | (1 << k)][k]
// base case: dp[(1 << i)][i] = 1
// the answer: dp[1 << n - 1][n - 1]
void add_self(int& a, int b){
    a += b;
    if(a >= M){
        a -= M;
    }
}
int main() {
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<vector<int>> dp(1 << n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
    }
    dp[1][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            for (int k : edges[j]) {
                if (!dp[mask][j] || (mask & (1 << k))) continue;
                // either it's not possible to get to this state or we've already visited k
                add_self(dp[mask | (1 << k)][k], dp[mask][j]);
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
}
