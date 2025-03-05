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
auto inside = [&](int r, int c) -> bool{
    return r >= 0 && r < R && c >= 0 && c < C;
};
auto encode = [&](int r, int c) -> int{
    return r * C + c;
};
auto decode = [&](int value) -> pair<int, int> {
    return make_pair(value / C, value % C);
};
auto get_move = [&](int from, int to) -> char {
    auto f = decode(from);
    auto t = decode(to);
    if(f.first + 1 == t.first){
        return 'D';
    } else if(f.first - 1 == t.first){
        return 'U';
    } else if(f.second + 1 == t.second){
        return 'R';
    } else {
        assert(f.second - 1 == t.second);
        return 'L';
    }
    assert(false);
};

vector<vector<bool>> vis(R, vector<bool>(C, false));
queue<pair<int, int>> q; // might enqueue some cells first
// queue<pair<int, int>> q({{r, c}});
// vis[r][c] = true; // might mark some cells as visited
while(!q.empty()){
    auto [r, c] = q.front(); q.pop();
    // do something here if want
    for(int dir = 0; dir < 4; dir++){
        int r2 = r + dx[dir];
        int c2 = c + dy[dir];
        if(inside(r2, c2) && !vis[r2][c2] && (true)){ // might add some condition
            vis[r2][c2] = true;
            q.push({r2, c2});
        }
    }
}
