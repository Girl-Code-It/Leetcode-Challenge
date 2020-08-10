class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty()){
            vector<int> v;
            while(!s1.empty()){
                TreeNode* top = s1.top();
                s1.pop();
                if(top) {
                    v.push_back(top->val);
                    if(top->left) s2.push(top->left);
                    if(top->right) s2.push(top->right);
                }
            }
            if(v.size()) ans.push_back(v);
            v.clear();
            while(!s2.empty()){
                TreeNode* top = s2.top();
                s2.pop();
                if(top) {
                    v.push_back(top->val);
                    if(top->right) s1.push(top->right);
                    if(top->left) s1.push(top->left);
                }
            }
            if(v.size()) ans.push_back(v);
        }
        return ans;
    }
};