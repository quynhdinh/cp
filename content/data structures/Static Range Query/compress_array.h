// For an array A of size N, you want to compress so every number is 0 <= A[i] < N
// References: https://codeforces.com/blog/entry/84164
vector<int> compress(vector<int> a){
  int n = a.size();
  vector<pair<int, int>> pairs(n);
  for(int i = 0; i < n; ++i) {
  	pairs[i] = {a[i], i};
  }
  sort(pairs.begin(), pairs.end());
  int nxt = 0;
  for(int i = 0; i < n; ++i) {
  	if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++; // remove `&& pairs[i - 1].first != pairs[i].first` if you want to make a permutation
  	a[pairs[i].second] = nxt;
  }
  return a;
}
