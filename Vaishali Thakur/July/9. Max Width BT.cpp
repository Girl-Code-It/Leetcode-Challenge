class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        int ans = 1;
        while(!q.empty()){
            int size = q.size();
            int mn = INT_MAX, mx = 0;
            while(size--){
                auto front = q.front();
                q.pop();
                
                int val = 2 * front.second;
                if(front.first->left){
                    q.push({front.first->left, val});
                    mn = min(mn, val);
                    mx = max(mx, val);
                } 
                if(front.first->right){
                    q.push({front.first->right, val - 1});
                    mn = min(mn, val - 1);
                    mx = max(mx, val - 1);
                }
            }
            
            mn = (mn == INT_MAX) ? 0 : mn;
            ans = max(ans, (mx - mn + 1));
        }
        
        return ans;
    }
};