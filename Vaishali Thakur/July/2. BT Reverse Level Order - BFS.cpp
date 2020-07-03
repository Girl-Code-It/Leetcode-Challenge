class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        
        if(root == NULL)
            return v;
        
        vector<int> v1;
            
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(q.empty()){
                v.push_back(v1);
                reverse(v.begin(), v.end());
                return v;
            }
            
            if(front){
                v1.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            } else {
                q.push(NULL);
                v.push_back(v1);
                v1.clear();
            }
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};