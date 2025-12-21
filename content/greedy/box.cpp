/* There are n (n ≤ 2000) boxes, i-th with weight wi and strength/durability si.
You can choose some subset of boxes and rearrange them in any order you like.
Find the maximum possible number of boxes in a tower where
the strength of a box must be not smaller than the sum of weights of boxes
above.*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> boxes(n);
  for (int i = 0; i < n; i++) {  // {weight, strength}
    cin >> boxes[i].first >> boxes[i].second;
  }
  /*
  consider box 1 and 2, if 1 is above 2, then
  s2 >= w1(1)
  if 2 is above 1, then s1 >= w2 (2)
  what makes box 1 above box 2 means (2) has to be false
  which means s1 < w2 <=> w2 > s1(3)
  (1) and (3) means s2 + w2 > s1 + w1
  so we can sort boxes by s + w, and then use dp to find the maximum
  */
  sort(begin(boxes), end(boxes), [](auto& me, auto& him) {
    return me.first + me.second < him.first + him.second;
  });
  const long long INF = (1LL << 60);
  vector dp(n + 1, vector<long long>(n + 1, INF)); // dp[pref][used]
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    auto [w, s] = boxes[i - 1];
    for (int used = 0; used <= i; used++) {
      // skip this box
      dp[i][used] = min(dp[i][used], dp[i - 1][used]);
      // take this box
      if (used > 0 && dp[i - 1][used - 1] <= s) {
        dp[i][used] = min(dp[i][used], dp[i - 1][used - 1] + w);
      }
    }
  }

  int ans = 0;
  for (int used = 0; used <= n; used++) {
    if (dp[n][used] < INF) ans = used;
  }
  cout << ans << "\n";
}