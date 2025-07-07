#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> tree[N];
int in[N], out[N], timer = 0;

void dfs(int node, int parent) {
    in[node] = ++timer;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
    out[node] = ++timer;
}

bool isInSubtree(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
    int u, v;
    cin >> u >> v; // query: is v in subtree of u?

    if (isInSubtree(u, v)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}