// Solution to various 'coin change' problem
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void add_self(int& a, int b){
    a += b;
    if(a >= mod) a -= mod;
}
void min_self(int& a, int b){
    a = min(a, b);
}
int main(){
    int n, target; cin>>n>>target;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> dp(target + 1, mod);
    dp[0] = 0;
    for(int i = 1; i <= target; i++){
        for(int j = 0; j < n; j++){
            if(i - a[j] >= 0){
                min_self(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout<<(dp[target] == mod ? -1 : dp[target])<<'\n';
}
