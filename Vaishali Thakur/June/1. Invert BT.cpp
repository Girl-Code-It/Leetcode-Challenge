class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        TreeNode* Left = NULL, *Right = NULL;
        if(root->left != NULL)
            Left = invertTree(root->left);
        if(root->right != NULL)
            Right = invertTree(root->right);
        
        root->left = Right;
        root->right = Left;
        return root;
    }
};