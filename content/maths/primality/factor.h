inline namespace factorBasic {
    template<class T> vector<pair<T,int>> factor(T x) { 
        vector<pair<T,int>> pri;
        for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.push_back({i,t});
        }
        if (x > 1) pri.push_back({x,1});
        return pri;
    }
    /* Note:
    * number of operations needed s.t.
    *				  phi(phi(...phi(n)...))=1
    * is O(log n).
    * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
    */
    long long phi(long long x) {
        for(const auto& a: factor(x)){
            x -=x/a.first;
        }
        return x;
    }
    template<class T> void tour(vector<pair<T,int>>& v, vector<T>& V, int ind, T cur) {
        if (ind == (int)v.size()) V.push_back(cur);
        else {
            T mul = 1;
            for(int i = 0; i < v[ind].second + 1; i++){
                tour(v,V,ind+1,cur*mul);
                mul *= v[ind].first;
            }
        }
    }
    template<class T> vector<T> getDivi(T x) {
        auto v = factor(x);
        vector<T> V;
        tour(v,V,0,(T)1);
        sort(V.begin(), V.end());
        return V;
    }
}
// Usage: vector<pair<int, int>> factors = factorBasic::factor<int>(120);
