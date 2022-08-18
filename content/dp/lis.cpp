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

// fast : https://github.com/ngthanhtrung23/ACM_Notebook_new/blob/master/DP/lis.h


// https://leetcode.com/problems/number-of-longest-increasing-subsequence
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 0, max_len = 0;
    vector<pair<int,int>> dp(n,{1,1});            //dp[i]: {length, number of LIS which ends with nums[i]}
    for(int i = 0; i<n; i++){
        for(int j = 0; j <i ; j++){
            if(nums[i] > nums[j]){
                if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
            }
        }
        if(max_len == dp[i].first)res += dp[i].second;
        if(max_len < dp[i].first){
            max_len = dp[i].first;
            res = dp[i].second;
        }
    }
    return res;
}