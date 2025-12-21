#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct fenwick_tree {
  static int highest_bit(unsigned x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
  }

  int tree_n = 0;
  T tree_sum = T();
  vector<T> tree;

  fenwick_tree(int n = -1) {
    if (n >= 0) init(n);
  }

  void init(int n) {
    tree_n = n;
    tree_sum = T();
    tree.assign(tree_n + 1, T());
  }

  template <typename T_array>
  void build(const T_array& initial) {
    assert(size(initial) == tree_n);
    tree_sum = T();
    for(int i = 1; i <= tree_n; i++){
      tree[i] = initial[i - 1];
      tree_sum += initial[i - 1];
      for(int k = (i & -i) >> 1; k > 0; k >> 1)
        tree[i] += tree[i - k];
    }
  }
  void update(int index, const T& change){
    assert(0 <= index && index < tree_n);
    tree_sum += change;
    for(int i = index + 1; i <= tree_n; i += i & -i)
      tree[i] += change;
  }
  // returns the sum of the range [0, count]
  T query(int count) const {
    count = min(count, tree_n);
    T sum = T();
    for(int i = count; i > 0; i -= i & -i)
      sum += tree[i];
    return sum;
  }
  T query_suffix(int start) const {
    return tree_sum - query(start);
  }

};
int32_t main(){

}