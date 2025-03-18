#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

#define int long long
const int LOG = 18;
const int ALPHABET_SIZE = 26;
struct Node {
    Node* child[ALPHABET_SIZE];
    Node*  par[LOG + 1];
    int high;
    Node(){
        REP(i, ALPHABET_SIZE) child[i] = nullptr;
        REP(i, LOG + 1) par[i] = nullptr;
        high = 0;
    }
};
const int MAX_NODE = 200200;
Node nodes[MAX_NODE];
int node_count;
Node* root;
Node* str[MAX_NODE];

Node* createNode(void){
    return &nodes[node_count++];
}
void addString(const string& s, int id){
    Node* p = root;
    for(char c: s){
        if(p->child[c - 'a'] == nullptr)
            p->child[c - 'a'] = createNode();
        p = p->child[c - 'a'];
    }
    str[id] = p;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
