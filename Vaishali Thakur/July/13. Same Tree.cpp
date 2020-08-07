class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        bool Left = isSameTree(p->left, q->left);
        bool Right = isSameTree(p->right, q->right);
        
        return Left && Right;
    }
};