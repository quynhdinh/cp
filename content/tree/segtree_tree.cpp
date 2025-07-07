#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> tree[N];
int in[N], out[N], flat[N], timer = 0;
int value[N];  // Original values at each node

// Segment tree
int seg[4 * N];

void dfs(int node, int parent) {
    in[node] = timer;
    flat[timer++] = value[node];
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
    out[node] = timer;
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = flat[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    return query(2 * id, l, m, ql, qr) + query(2 * id + 1, m + 1, r, ql, qr);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        seg[id] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * id, l, m, pos, val);
    else update(2 * id + 1, m + 1, r, pos, val);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

int main() {
    int n;
    cin >> n;

    // Read values at each node
    for (int i = 0; i < n; ++i)
        cin >> value[i];

    // Read edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Flatten tree
    dfs(0, -1);

    // Build segment tree over flattened tree
    build(1, 0, n - 1);

    // Example: subtree sum query
    int u;
    cin >> u;
    int l = in[u], r = out[u] - 1;
    cout << "Subtree sum of node " << u << " is " << query(1, 0, n - 1, l, r) << "\n";

    // Example: point update at node v
    int v, newVal;
    cin >> v >> newVal;
    update(1, 0, n - 1, in[v], newVal);

    // New query after update
    cout << "Updated subtree sum of node " << u << " is " << query(1, 0, n - 1, l, r) << "\n";

    return 0;
}