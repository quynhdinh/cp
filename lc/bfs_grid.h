// const int dx[8] = {-1, -1, -1,  0, +1, +1, +1,  0};
// const int dy[8] = {-1,  0, +1, +1, +1,  0, -1, -1};

// for(int r = 0; r < R; r++){
//     for(int c = 0; c < C; c++){
//     }
// }
const vector< pair<int,int> > dirs = {
    {-1, 0},  // down
    {0, -1},  // left
    {1, 0},   // up
    {0, 1},   // right
};
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int R = grid.size(), C = grid[0].size(); // check height if needed
auto inside = [&](int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
};

vector<vector<bool>> vis(R, vector<bool>(C, false));
queue<pair<int, int>> q; // might enqueue some cells first
// queue<pair<int, int>> q({{r, c}});
// vis[r][c] = true; // might mark some cells as visited
while(!q.empty()){
    auto [r, c] = q.front(); q.pop();
    // do something here if want
    for(auto [dx, dy]: dirs){
        int r2 = r + dx;
        int c2 = c + dy;
        if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && !vis[r2][c2] && (true)){ // might add some condition
            vis[r2][c2] = true;
            q.push({r2, c2});
        }
    }
}
