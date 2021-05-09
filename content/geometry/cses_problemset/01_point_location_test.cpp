#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
    void read(){
        cin>>x>>y;
    }
    P operator+(const P&other) const{
        return P{x + other.x, y + other.y};
    }
    P operator-(const P&other) const{
        return P{x - other.x, y - other.y};
    }
    long long operator*(const P&other){
        return (long long)x * other.y - (long long)y * other.x;
    }
};
void test_case(){
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
	//make it relative to p1(p1 is now the origin O)
    p3 = p3 - p1;
    p2 = p2 - p1;
    long long cross_product = p3 * p2;
    if(cross_product > 0){
        cout<<"RIGHT"<<'\n';
    }
    else if(cross_product < 0){
        cout<<"LEFT"<<'\n';
    }
    else{
        cout<<"TOUCH"<<'\n';
    }
}
int32_t main(){
    int tt; cin>>tt;
    while(tt--){
        test_case();
    }
}