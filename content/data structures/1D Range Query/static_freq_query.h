/**
 * Description: Given an array. Given Q query l, r, x
 	* Print the number of times x occurs in a_{l},..., a_{r - 1}
 * Time: O(log N)
 * Source & Verification: https://judge.yosupo.jp/problem/static_range_frequency
 */
struct FreqTable{
    map<int, vector<int>> mp;
    void init(vector<int> a){
        for(int i = 0; i < (int)a.size(); i++){
            mp[a[i]].push_back(i);
        }
    }
    int query(int l, int r, int x){
        const std::vector<int> &v = mp[x];
        const int ans = std::lower_bound(v.begin(), v.end(), r) -
                        std::lower_bound(v.begin(), v.end(), l);
        return ans;
    }
};

// FreqTable table;
// table.init(a);
// table.query