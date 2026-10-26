// L[i][j]: the number of substring ends at i that have j distinct characters
// R[i][j]: the number of substring starts at i that have j distinct characters

vector L(n, vector<int>(27)), R(n, vector<int>(27));
vector<int> pos(26, -1);
for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'] = i;
    int p[26], sz = 0;
    for (int x : pos) if (x != -1) p[sz++] = x;
    sort(p, p + sz, greater<int>());
    for (int k = 0; k < sz; ++k) {
        L[i][k + 1] = p[k] - (k + 1 < sz ? p[k + 1] : -1);
    }
}
pos.assign(26, n);
for (int i = n - 1; i >= 0; --i) {
    pos[s[i] - 'a'] = i;
    int sz = 0;
    vector<int> q(26);
    for (int x : pos) if (x != n) q[sz++] = x;
    sort(begin(q), begin(q) + sz);
    for (int k = 0; k < sz; ++k)
        R[i][k + 1] = (k + 1 < sz ? q[k + 1] : n) - q[k];
}
