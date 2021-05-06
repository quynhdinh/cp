#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
    void read(){
        cin>>x>>y;
    }
    P operator-(const P&other) const{
        return P{x - other.x, y - other.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    long long operator*(const P&other){
        return (long long)x * other.y - (long long)y * other.x;
    }
    long long triangle(const P& b, const P& c) const{
        return (b - *this) * (c - *this);
    }
};
void test_case(){
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    if((p2 - p1) * (p4 - p3) == 0){
        //two segment are parallel
        //if((p2 - p1) * (p3 - p1) != 0)
        if(p1.triangle(p2, p3) != 0){ // trung nhau
            cout<<"NO\n";
            return;
        }
        //check if two bounding boxes intersect
        for(int rep = 0; rep < 2; rep++){
            //rectangle A on left from rectangle B or A below rectangle B
            if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                cout<<"NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout<<"YES\n";
        return;
    }
    for(int rep = 0; rep < 2; rep++){
        long long sign1 = (p2 -p1) * (p3 - p1);
        long long sign2 = (p2 -p1) * (p4 - p1);
        if((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)){
            //segment B is on the left or right from line A
            cout<<"NO\n";
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout<<"YES\n";
}
int32_t main(){
    int tt; cin>>tt;
    while(tt--){
        test_case();
    }
}