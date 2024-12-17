// count number of node in binary tree
// n = 0;
// dfs(root);
int n;
map<TreeNode*, int> nodeToLabel;
map<int, TreeNode*> labelToNode;
void dfs(TreeNode* root){
    if(root){
        nodeToLabel[root] = n;
        labelToNode[n] = root;
        n++;
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
}

// build a graph from binary tree TreeNode*
// Note: may use a 2d array for performance if possible
// vector<vector<int>> g(n);
unordered_map<int, vector<int>> g;
stack<TreeNode*> st({root});
while(!st.empty()){
    TreeNode* tp = st.top();
    st.pop();
    if(tp->left){
        g[tp->left->val].push_back(tp->val);
        g[tp->val].push_back(tp->left->val);
        st.push(tp->left);
    }
    if(tp->right){
        g[tp->right->val].push_back(tp->val);
        g[tp->val].push_back(tp->right->val);
        st.push(tp->right);
    }
}
queue<int> q({start});
unordered_set<int> vis({start}); // may use vector for performance if possible
// vector<bool> vis(n, false); vis[start] = true;
while(!q.empty()){
    int fr = q.front(); q.pop();
    for(int& nei: g[fr]){
        if(!vis.count(nei)){
            vis.insert(nei);
            q.push(nei);
        }
    }
}
