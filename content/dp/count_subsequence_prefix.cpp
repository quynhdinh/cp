class Solution {
public:
    const int mod = 1e9 + 7;
    int countPalindromes(string s) {
        int n = s.size(), res = 0;
        vector<int> cnts(10);
        vector<vector<vector<int>>> pref(n, vector<vector<int>>(10, vector<int>(10)));
        vector<vector<vector<int>>> suf(n, vector<vector<int>>(10, vector<int>(10)));
        // pref[i][j][k] means the number of subsequence of jk in [0, i]
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if (i > 0)
                for (int j = 0; j < 10; j++)
                    for (int k = 0; k < 10; k++) {
                        pref[i][j][k] = pref[i - 1][j][k];
                        if (k == c) 
                            pref[i][j][k] += cnts[j];
                    }
            cnts[c]++;
        }
        cnts.assign(10, 0);
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - '0';
            if (i < n - 1)
                for (int j = 0; j < 10; j++)
                    for (int k = 0; k < 10; k++) {
                        suf[i][j][k] = suf[i + 1][j][k];
                        if (k == c) suf[i][j][k] += cnts[j];
                    }
            cnts[c]++;
        }
        for (int i = 2; i < n - 2; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    res = (res + 1LL * pref[i - 1][j][k] * suf[i + 1][j][k]) % mod;
        return res;
    }
};
