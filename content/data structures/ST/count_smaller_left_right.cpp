#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
struct SegmentTree {
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start]};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            merge(tree[2 * node + 1], tree[2 * node + 2], tree[node]);
        }
    }

    void merge(const vector<int>& left, const vector<int>& right, vector<int>& node) {
        node.clear();
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                node.push_back(left[i]);
                i++;
            } else {
                node.push_back(right[j]);
                j++;
            }
        }
        while (i < (int)left.size()) node.push_back(left[i++]);
        while (j < (int)right.size()) node.push_back(right[j++]);
    }

    int query(int node, int node_left, int node_right, int query_left, int query_right, int value) {
        if (query_right < node_left || node_right < query_left) return 0;
        if (query_left <= node_left && node_right <= query_right) {
            return lower_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
        }
        int mid = (node_left + node_right) / 2;
        return query(2 * node + 1, node_left, mid, query_left, query_right, value) +
               query(2 * node + 2, mid + 1, node_right, query_left, query_right, value);
    }

    int countSmallerThan(int l, int r, int value) {
        return query(0, 0, n - 1, l, r, value);
    }
    vector<vector<int>> tree;
    int n;
};

int countSmallerLeft(const vector<int>& arr, int index) {
    if (index < 0 || index >= (int)arr.size()) return -1;

    SegmentTree segTree(arr.size());
    segTree.build(arr, 0, 0, arr.size() - 1);
    debug(segTree.tree[0]);

    return segTree.countSmallerThan(0, index - 1, arr[index]);
}

int main() {
    vector<int> arr = {3, 5, 2, 8, 6};
    int index = 4;
    int result = countSmallerLeft(arr, index);
    cout << result << '\n';
    return 0;
}