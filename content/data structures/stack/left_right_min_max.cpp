#include<bits/stdc++.h>
using namespace std;
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
int main(){
    int n; cin>>n;
    vector<int> a(n), leftMin(n), leftMax(n), rightMin(n), rightMax(n);
    // leftMax[i]: the left most j s.t. a[j] <= a[i]
    REP(i, n)
        cin>>a[i];
    auto calcRange = [&](vector<int>& left, vector<int>& right) {
        stack<int> st;
        REP(i, n){
            while (!st.empty() && a[st.top()] < a[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        FORD(i, n - 1, 0){
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
    };
    calcRange(leftMax, rightMax);
    REP(i, n) a[i] *= -1;
    calcRange(leftMin, rightMin);
    REP(i, n) a[i] *= -1;
}