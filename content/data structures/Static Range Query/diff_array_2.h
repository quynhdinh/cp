vector<vector<int>> diff_array_2(const vector<vector<int>> &grid, const vector<tuple<int, int, int, int>> &ops) {
    vector<vector<int>> result = grid;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> upd(n, vector<int>(m));
    for (auto [x1, y1, x2, y2]: ops) {
        upd[x1][y1]++;
        if (x2 + 1 < n) upd[x2 + 1][y1]--;
        if (y2 + 1 < m) upd[x1][y2 + 1]--;
        if (x2 + 1 < n and y2 + 1 < m) upd[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            upd[i][j] += upd[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            upd[i][j] += upd[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[i][j] += upd[i][j];
    return result;
}