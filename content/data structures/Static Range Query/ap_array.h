vector<int> ap_update(const vector<int> &a, const vector<pair<int, int>> &ops) {
    int n = a.size();
    vector<int> pref(n);
    for (auto &[l, r]: ops) {
        pref[l]++;
        if (r + 1 < n) {
            pref[r + 1]--;
        }
    }
    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }
    for (auto &[l, r]: ops) {
        if (r + 1 < n) {
            pref[r + 1] -= (r - l + 1);
        }
    }
    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }
    vector<int> result = a;
    for (int i = 0; i < n; i++) {
        result[i] += pref[i];
    }
    return result;
}