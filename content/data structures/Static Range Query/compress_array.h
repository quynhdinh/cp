// For an array A of size N, you want to compress so every number is 0 <= A[i] < N
// References: https://codeforces.com/blog/entry/84164
// permutation: return a permutation [0, n)
template<typename T>
vector<T> compress_array(vector<T> a, bool permutation){
    const int n = (int)a.size();
    vector<pair<T, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        pairs[i] = {a[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = 0;
    for(int i = 0; i < n; ++i) {
        if(i > 0){
            if(!permutation && pairs[i - 1].first != pairs[i].first)
                nxt++;
            else {
                nxt++;
            }
        }
        a[pairs[i].second] = nxt;
    }
    return a;
}
