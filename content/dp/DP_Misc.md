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
/**
 *    created: 16.07.2025_23:08:37
**/
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