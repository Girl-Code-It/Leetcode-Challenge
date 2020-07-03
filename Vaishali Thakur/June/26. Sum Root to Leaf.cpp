class Solution {
public:
    int helper(TreeNode* root, int sum){
        if(root == NULL)
            return 0;
        
        sum = sum * 10 + root->val;
        if(!root->left && !root->right)
            return sum;
        
        int Left = helper(root->left, sum);
        int Right = helper(root->right, sum);
        return Left + Right;
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);   
    }
};