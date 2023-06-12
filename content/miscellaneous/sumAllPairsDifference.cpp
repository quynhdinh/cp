    int sumDistanceOfAllPairs(vector<int> a, int mod = 0){
        sort(a.begin(), a.end());
        long long res = 0LL;
        long long prefix = 0LL;
        int n = a.size();
        for(int i = 0; i < n; i++){
            res += ((long long)i * a[i] - prefix);
            if(mod != 0){
                res %= mod;
            }
            prefix += (long long)a[i];
        } 
        return res;
    }