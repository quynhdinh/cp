UVa 10003 - Cutting Sticks
```cpp

#include <bits/stdc++.h>
using namespace std;

int l, n, A[55], memo[55][55];

int cut(int left, int right) {
  if (left+1 == right) return 0;
  int &ans = memo[left][right];
  if (ans != -1) return ans;
  ans = 2e9;
  for (int i = left+1; i < right; ++i)
    ans = min(ans, cut(left, i) + cut(i, right) + (A[right]-A[left]));
  return ans;
}

int main() {
  while (scanf("%d", &l), l) {
    A[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &A[i]);
    A[n+1] = l;
    memset(memo, -1, sizeof memo);
    printf("The minimum cutting is %d.\n", cut(0, n+1)); // start with left = 0 and right = n+1
  }
  return 0;
}
```

10912 - Simple Minded Hashing
```cpp
#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    vector dp(27, vector<vector<int>>(27, vector<int>(352)));
    dp[0][0][0] = 1;
    for(int i = 1; i <= 26; i++)
        for(int j = 0; j <= i; j++)
            for(int k = 0; k < 352; k++){
                dp[i][j][k] = dp[i - 1][j][k];
                if(j > 0 && k >= i){
                    dp[i][j][k] += dp[i - 1][j - 1][k - i];
                }
            }
    int l, s, Case = 0;
    while(scanf("%d %d", &l, &s) == 2){
        if(l == 0 && s == 0) break;
        printf("Case %d: ", ++Case);
        if(l > 26 || s > 351)
            puts("0");
        else printf("%d\n", dp[26][l][s]);
    }
    return 0;
}
```

11420 - Chest of Drawers
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lock 0
#define unlock 1
int32_t main(){
    int n , s;
    vector dp(70, vector<vector<ll>>(70, vector<ll>(2, -1)));
    function<ll(int, int, int)> solve = [&](int pos, int cntSecure, int prev) -> ll{
        if (pos < 0 || cntSecure < 0 || prev < 0 )return 0;
        else if(pos == 0 && cntSecure == 0) return 1;
        ll &ret = dp[pos][cntSecure][prev];
        if (ret != -1) return ret;
        if (prev == lock) ret = solve(pos - 1, cntSecure - 1, lock) + solve(pos - 1, cntSecure,unlock);
        else ret = solve(pos - 1, cntSecure, lock) + solve(pos - 1, cntSecure, unlock);
        return ret;
    };
    while(scanf("%d %d",&n,&s)){
        if(n < 0) break;
        ll ret = solve(n,s,lock);
        printf("%lld\n",ret);
    }
    return 0;
}
```

11450 - Wedding Shopping

```cpp
// UVa 11450 - Wedding Shopping - Top Down
#include <bits/stdc++.h>
using namespace std;

const int MAX_gm = 30; // up to 20 garments at most and 20 models/garment
const int MAX_M = 210; // maximum budget is 200

int M, C, price[MAX_gm][MAX_gm]; // price[g (<= 20)][k (<= 20)]
int memo[MAX_gm][MAX_M]; // TOP-DOWN: dp table [g (< 20)][money (<= 200)]

int dp(int g, int money) {
  if (money < 0) return -1e9;                    // must check this first
  if (g == C) return M-money;                    // money can't be < 0
  int &ans = memo[g][money];                     // remember memory address
  if (ans != -1) return ans;
  for (int k = 1; k <= price[g][0]; ++k)         // try each model k
    ans = max(ans, dp(g+1, money-price[g][k]));
  return ans;                                    // ans == memo[g][money]
}
int main() {                                     // easy to code
  int TC; scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &M, &C);
    for (int g = 0; g < C; ++g) {
      scanf("%d", &price[g][0]);                 // store k in price[g][0]
      for (int k = 1; k <= price[g][0]; ++k)
        scanf("%d", &price[g][k]);
    }
    memset(memo, -1, sizeof memo);               // TOP-DOWN: init memo
    if (dp(0, M) < 0) printf("no solution\n");   // start the top-down DP
    else              printf("%d\n", dp(0, M));
  }
  return 0;
}
```