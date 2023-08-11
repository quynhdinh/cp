vector<int> diff_array(const vector<int>& a, const vector<tuple<int, int, int>>& ops){
	const int n = a.size();
	vector<int> pref(n);
	vector<int> result(n);
	for(const auto& tuple: ops){ // versions earlier than C++17 doesn't have that deep access, i.e: for(auto& [l, r, d]: ops){
		int l = get<0>(tuple);
		int r = get<1>(tuple);
		int d = get<2>(tuple);
		pref[l] += d;
		if (r != n - 1)
			pref[r + 1] -= d;
	}
	for(int i = 1; i < n; i++){
		pref[i] += pref[i - 1];
	}
	for(int i = 0; i < n; i++){
		result[i] = a[i] + pref[i];
	}
	return result;
}
