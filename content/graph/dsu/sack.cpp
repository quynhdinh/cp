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
// CF - lomsat Gelral
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define ll long long
using namespace std;

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int)v.size();

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

struct CNT {
    map<int, int> cnt; // cnt[c]: the number of vertex in subtree has color c
    int max_freq;
    ll sum; // sum of those colors have max_freq

    void init() {
        cnt.clear();
        max_freq = -1;
        sum = 0;
    }

    void add(int c, int x) {
        cnt[c] += x;
        if (cnt[c] > max_freq) {
            max_freq = cnt[c];
            sum = c;
        } else if (cnt[c] == max_freq)
            sum += c;
    }
};
int main() {
    int n; cin>>n;
    vector<int> colors(n), id(n);
    vector<ll> res(n);
    int nId = 0;
    vector<CNT> cnt(n);
    vector<vector<int>> g(n);
    REP(i, n)
        cin>>colors[i];
    for(int i = 0; i < n - 1; i++){
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    REP(i, n) cnt[i].init();
    function<void(int, int)> dfs = [&](int u, int parent) {
        int best = -1;
        for(int v : g[u]) {
            if (v == parent) continue;
            dfs(v, u);
            if (best < 0 || cnt[id[v]].cnt.size() > cnt[best].cnt.size())
                best = id[v];
        }
        if (best < 0) // this is leaf
            best = ++nId;
        id[u] = best;
        cnt[id[u]].add(colors[u], +1);
        for(auto v : g[u]) {
            if (v == parent) continue;
            if (id[v] == id[u]) continue;
            for(auto p : cnt[id[v]].cnt)
                cnt[id[u]].add(p.first, p.second);
        }
        res[u] = cnt[id[u]].sum;
    };
    dfs(0, -1);
    output_vector(res);
}
