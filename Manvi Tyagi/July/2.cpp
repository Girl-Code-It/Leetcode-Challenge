class Solution
{
public:
    void dfs(TreeNode *root, int level, vector<vector<int>> &ans)
    {
        if (!root)
            return;

        if (ans.size() <= level)
            ans.resize(level + 1);

        ans[level].push_back(root->val);

        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> revans;
        dfs(root, 0, revans);
        reverse(revans.begin(), revans.end());
        return revans;
    }
};