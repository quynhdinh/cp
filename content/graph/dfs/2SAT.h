/**
 * Description: 
 * Time: O(N+M)
 * Usage: TwoSat sat(N); // N is the number of arguments
 * sat.add_cond(x, a_bool, y, b_bool); // x, y must be 0-based, {a, b}_bool is the sign
 * sat.exec() -> satisfiable or not -> sat.res[0..N - 1]
 * Source & Verification: https://judge.yosupo.jp/problem/two_sat
 */
struct SCC{
    vector<int> id;
    vector<vector<int>> groups;
};
 
template <class E>
struct SCCExec : SCC
{
    int n;
    const vector<vector<E>> &g;
    int tm = 0;
    vector<bool> flag;
    vector<int> low, ord, st, gr;
    void dfs(int v){
        low[v] = ord[v] = tm++;
        st.push_back(v);
        flag[v] = true;
        for (auto e : g[v]){
            if (ord[e.to] == -1){
                dfs(e.to);
                low[v] = min(low[v], low[e.to]);
            }
            else if (flag[e.to]){
                low[v] = min(low[v], ord[e.to]);
            }
        }
        if (low[v] == ord[v]){
            gr.clear();
            while (true){
                int u = st.back();
                st.pop_back();
                gr.push_back(u);
                if (u == v)
                    break;
            }
            for (int x : gr)
                flag[x] = false;
            groups.push_back(gr);
        }
    }
    SCCExec(const vector<vector<E>> &_g)
        : n(int(_g.size())), g(_g), flag(n), low(n), ord(n, -1){
        id = vector<int>(n);
        for (int i = 0; i < n; i++){
            if (ord[i] == -1)
                dfs(i);
        }
        reverse(groups.begin(), groups.end());
        for (int i = 0; i < int(groups.size()); i++){
            for (int x : groups[i]){
                id[x] = i;
            }
        }
    }
};
 
template <class E>
SCC get_scc(const vector<vector<E>> &g) { return SCCExec<E>(g); }
 
struct TwoSat {
    vector<bool> res;
    struct Edge {
        int to;
    };
    vector<vector<Edge>> g;
    void add_cond(int a, bool a_exp, int b, bool b_exp) {
        g[2 * a + (a_exp ? 0 : 1)].push_back(Edge{2 * b + (b_exp ? 1 : 0)});
        g[2 * b + (b_exp ? 0 : 1)].push_back(Edge{2 * a + (a_exp ? 1 : 0)});
    }
    bool exec() {
        int n = int(res.size());
        auto s = get_scc(g);
        for (int i = 0; i < n; i++) {
            if (s.id[2 * i] == s.id[2 * i + 1]) return false;
            res[i] = s.id[2 * i] < s.id[2 * i + 1];
        }
        return true;
    }
    TwoSat() {}
    TwoSat(int n) {
        g = vector<vector<Edge>>(2 * n);
        res = vector<bool>(n);
    }
};