// count number of node in binary tree
// n = 0;
// dfs(root);
int n;
void dfs(TreeNode* root){
    if(root){
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
    TreeNode* root = st.top();
    st.pop();
    if(root->left){
        g[root->left->val].push_back(root->val);
        g[root->val].push_back(root->left->val);
        st.push(root->left);
    }
    if(root->right){
        g[root->right->val].push_back(root->val);
        g[root->val].push_back(root->right->val);
        st.push(root->right);
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