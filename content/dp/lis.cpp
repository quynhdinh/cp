int n = a.size();
vector<int> dp(n), pre(n);
// sort(a.begin(), a.end());
int max = 0, index = -1;
for (int i = 0; i < n; i++) {
    dp[i] = 1;
    pre[i] = -1;
    for(int j = 0; j < i; j++){
        if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            pre[i] = j;
        }
    }
    if (dp[i] > max) {
        max = dp[i];
        index = i;
    }
}
//Construct a LIS
vector<int> res;
while (index != -1) {
    res.push_back(a[index]);
    index = pre[index];
}
return max;

// For test: https://leetcode.com/problems/longest-increasing-subsequence/
// Similar: https://leetcode.com/problems/largest-divisible-subset/
// https://leetcode.com/problems/russian-doll-envelopes/
// https://leetcode.com/problems/maximum-length-of-pair-chain/
// https://leetcode.com/problems/best-team-with-no-conflicts/

// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/(harder)

// fast : https://github.com/ngthanhtrung23/ACM_Notebook_new/blob/master/DP/lis.cpp