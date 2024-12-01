    vector<vector<int>> adjList(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> a(n);
        for (const auto& e : edges)
            a[e[0]].push_back(e[1]), a[e[1]].push_back(e[0]);
        return a;
    }
    // auto g1 = adjList(n, edges1);