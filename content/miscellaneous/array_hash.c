template<int mod>
inline unsigned int down(unsigned int x) {
	return x >= mod ? x - mod : x;
}

template<int mod>
struct Modint {
	unsigned int x;
	Modint() = default;
	Modint(unsigned int x) : x(x) {}
	// friend istream& operator>>(istream& in, Modint& a) {return in >> a.x;}
	// friend ostream& operator<<(ostream& out, Modint a) {return out << a.x;}
	friend Modint operator+(Modint a, Modint b) {return down<mod>(a.x + b.x);}
	friend Modint operator-(Modint a, Modint b) {return down<mod>(a.x - b.x + mod);}
	friend Modint operator*(Modint a, Modint b) {return 1ULL * a.x * b.x % mod;}
	// friend Modint operator/(Modint a, Modint b) {return a * ~b;}
	// friend Modint operator^(Modint a, int b) {Modint ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans;}
	// friend Modint operator~(Modint a) {return a ^ (mod - 2);}
	friend Modint operator-(Modint a) {return down<mod>(mod - a.x);}
	// friend Modint& operator+=(Modint& a, Modint b) {return a = a + b;}
	// friend Modint& operator-=(Modint& a, Modint b) {return a = a - b;}
	// friend Modint& operator*=(Modint& a, Modint b) {return a = a * b;}
	// friend Modint& operator/=(Modint& a, Modint b) {return a = a / b;}
	// friend Modint& operator^=(Modint& a, int b) {return a = a ^ b;}
	// friend Modint& operator++(Modint& a) {return a += 1;}
	// friend Modint operator++(Modint& a, int) {Modint x = a; a += 1; return x;}
	// friend Modint& operator--(Modint& a) {return a -= 1;}
	// friend Modint operator--(Modint& a, int) {Modint x = a; a -= 1; return x;}
	friend bool operator==(Modint a, Modint b) {return a.x == b.x;}
	// friend bool operator!=(Modint a, Modint b) {return !(a == b);}
};

const int P1 = 998244353, B1 = 1212121;
// const int P2 = 1004535809, B2 = 23333;

typedef Modint<P1> Hash1;
// typedef Modint<P2> Hash2;

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<Hash1> pw1(n + 1);
        // vector<Hash2> pw2(n + 1);
        pw1[0] = 1;
        // pw2[0] = 1;
        for(int i = 1; i <= n; ++i) {
            pw1[i] = pw1[i - 1] * B1;
            // pw2[i] = pw2[i - 1] * B2;
        }
        vector<Hash1> h1(n + 1);
        // vector<Hash2> h2(n + 1);
        h1[0] = 0;
        // h2[0] = 0;
        for(int i = 1; i <= n; ++i) {
            h1[i] = h1[i - 1] * B1 + nums[i - 1];
            // h2[i] = h2[i - 1] * B2 + nums[i - 1];
        }
        auto getHash1 = [&](int l, int r) -> Hash1 {
            ++l; ++r;
            return h1[l - 1] * pw1[r - l + 1] - h1[r];
        };
        // auto getHash2 = [&](int l, int r) -> Hash2 {
        //     ++l; ++r;
        //     return h2[l - 1] * pw2[r - l + 1] - h2[r];
        // };
        auto isPrefix = [&](int l1, int r1, int l2, int r2) -> bool {
            if(r1 - l1 > r2 - l2) return false;
            return getHash1(l1, r1) == getHash1(l2, l2 + r1 - l1);
            // && getHash2(l1, r1) == getHash2(l2, l2 + r1 - l1);
        };
        // [0, i - 1]; [i, j - 1]; [j, n - 1]
        for(int i = 1; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(isPrefix(0, i - 1, i, j - 1) || isPrefix(i, j - 1, j, n - 1)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};