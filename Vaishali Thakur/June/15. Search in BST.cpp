class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val == val)
                return root;
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};