class Solution {
public:
    int h = -1; // max depth
    vector<vector<int>> ans;
    
    void dfs(TreeNode* root, int d)
    {
        if(root == NULL) return;
        if(d > h) ans.push_back({}) ,h+=1;
        
        ans[d].push_back(root->val);
        dfs(root->left,d+1);
        dfs(root->right,d+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        dfs(root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};