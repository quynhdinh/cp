/*
Hero (Potyczki 2014)
Bitor has H health points and he must defeat n (n ≤ 10^5) monsters.
The i-th monster deals di damage, but after death it drops a potion that restores ai hp (hp can be above the initial value). Can Bitor choose the order of fights in such a way that his hp never drops below 0? Print "NO" or "YES" with the order of monsters.
Bonus: n ≤ 2000 and maximize the number of defeated monsters.
*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> monsters(n);
  for (int i = 0; i < n; i++) {
    cin >> monsters[i].first >> monsters[i].second; // {damage, heal}
  }
  // consider two monster 1 and 2, if we fight 1 then 2, then
  // h1 - d1 + h2 - d2 >= 0 => h2 - d2 >= d1 - h1 (1)
  // if we fight 2 then 1, then
  // h2 - d2 + h1 - d1 >= 0 (2)
  // we want to fight 1 then 2, which means (2) has to be false
  // which means h2 - d2 + h1 - d1 < 0
  // which means d2 - h2 > h1 - d1

  sort(begin(monsters), end(monsters), [](auto& me, auto& him) {
    return me.first - me.second < him.first - him.second;
  });
  debug(monsters);
  for (auto [d, a] : monsters) {
    if (h <= d) {
      cout << "NO\n";
      return 0;
    }
    h += a - d;
  }
  
  cout << "YES\n";
  for (auto [d, a] : monsters) {
    cout << d << ' ' << a << '\n';
  }
}