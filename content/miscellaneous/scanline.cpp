/**
 *    created: 07.12.2024_17:11:52
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++)
        cin>>l[i]>>r[i];
    vector<int> order(n);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j){
        return l[i] < l[j];
    });
    // suppose l[1] <= l[2] <= .. <= l[r]
    // we pick k subsegments s[1] < s[2], .. < s[k]
    // we want s[1], s[2], .. s[k] intersect at some point
    // <=> max(l[s[1]], l[s[2]], .. , l[s[k]]) <= min(r[s[1]], r[s[2]], .. , r[s[k]])
    // <=> l[s[k]] <= min(r[s[1]], r[s[2]], .. , r[s[k]])
    // <=> l[s[k]] <= r[s[1]] and l[s[k]] <= r[s[2]] and .. and l[s[k]] <= r[s[k - 1]]
    multiset<int> rs; // all right borders
    for(int i = 0; i < n; i++){
        while(!empty(rs) && *rs.begin() < l[order[i]]){
            rs.erase(begin(rs));
        }
        // cnt: number of segments their index is smaller than the index of the current segment
        // and their right border is at least the left border of the current segment
        int cnt = (int)size(rs);
        int brute = 0;
        for(int j = 0; j < i; j++){
            if(r[order[j]] >= l[order[i]]){
                brute++;
            }
        }
        assert(cnt == brute);
        rs.insert(r[order[i]]);
    }
    /*
    vector<pair<int, int>> events;
    for(int i = 1; i <= n; i++){
        events.emplace_back(l, -i);
        events.emplace_back(r, +i);
    }
    sort(events.begin(), events.end());
    int current = 0;
    for (auto &e : events)
        if (e.second < 0) {
            current++;
        } else {
            current--;
            // current: the number of events still up instant e.first
        }
    }
    */
    return 0;
}