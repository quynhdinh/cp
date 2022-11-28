// Given some intervals, you want to pick maximum number of intervals that they are disjoint.
// Verification: https://www.spoj.com/problems/BUSYMAN/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt; cin>>tt;
    while(tt--){
        vector<pair<int, int>> a;
        int n; cin>>n;
        for(int i = 0; i < n; i++){
            int x, y; cin>>x>>y;
            a.emplace_back(make_pair(x, y));
        }
        sort(a.begin(), a.end(), [&](pair<int, int> f, pair<int, int> s){
             if(f.second == s.second) return f.first < s.first;
             return f.second < s.second;
        });
        int answer = 0, end = -1;
        for(auto x: a){
                if(end <= x.first){
                    answer++;
                    end = x.second;
                }
        }
        cout<<answer<<'\n';
    }
}
 