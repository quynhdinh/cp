// Given an array a1, a2, .., aN
// You want to find quick |ax - a1| + |ax - a2| + ... + |aN - ax|
vector<int> pref(n);
pref[0] = a[0];
for(int i = 1; i < n; i++){
    pref[i] = pref[i - 1] + (long long)a[i];
}
auto get_sum = [&](int l, int r){
    return (pref[r] - (l == 0 ? 0 : pref[l - 1]));
};

auto get = [&](int st, int en, int mid){
    int costLeft = (a[mid] * (mid - st + 1)) - get_sum(st, mid);
    int costRight = get_sum(mid, en) - a[mid] * (en - mid + 1));
    return costLeft + costRight;
};
