// verification: https://leetcode.com/problems/sliding-window-maximum
template<typename T>
vector<T> mink(const vector<T>& a, int k) {
  deque<pair<int, int>> q; // {index, value}
  auto add = [&] (int id, T val) {
    while (!empty(q) && q.back().second >= val) q.pop_back();
    q.push_back({id, val});
  };
  auto rem = [&] (int lower_bound) {
    if (!empty(q) && q.front().first <= lower_bound) q.pop_front();
  };
  int n = a.size();
  vector<T> res(n - k + 1);
  for (int i = 0; i < n; ++i) {
    add(i, a[i]);
    if (i >= k-1) {
      rem(i - k);
      res[i-k+1] = q.front().second;
    }
  }
  return res;
}
