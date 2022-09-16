/*
 * Description: Check if graph is bipartie and color it
 * Source: https://github.com/ngthanhtrung23/ACM_Notebook_new/blob/master/Graph/bipartite_edge_coloring.h
 * Verification:
   * https://cses.fi/problemset/task/1668/
 */
/*
 * Usage: auto [isBipartie, coloring] = get_diameter(g);
 * */
pair<bool, vector<int>> bipartite_coloring(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> color(n, -1);

    std::function<void(int)> dfs = [&] (int u) {
        for (int v : g[u]) {
            if (color[v] < 0) {
                color[v] = 3 - color[u];
                dfs(v);
            } else if (color[u] == color[v]) {
                throw 1;
            }
        }
    };

    try {
        for (int i = 0; i < n; i++) {
            if (color[i] < 0) {
                color[i] = 1;
                dfs(i);
            }
        }
    } catch (...) {
        return {false, {}};
    }
    return {true, color};
}