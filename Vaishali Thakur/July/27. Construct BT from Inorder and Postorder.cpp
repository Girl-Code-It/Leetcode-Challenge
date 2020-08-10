class Solution {
public:
    TreeNode* helper(vector<int>& in,int inS,int inE,vector<int>& post,int postS,int postE){
        if(inS > inE)
            return NULL;
        TreeNode* root = new TreeNode(post[postE]);
        int x = 0;
        while(in[x] != post[postE]){
            x++;
        }
        
        int inLS = inS;
        int inLE = x - 1;
        int inRS = x + 1;
        int inRE = inE;
        int postLS = postS;
        int postLE = inLE - inLS + postLS; 
        int postRS = postLE + 1;
        int postRE = postE - 1;
        
        root->left = helper(in, inLS, inLE, post, postLS, postLE);
        root->right = helper(in, inRS, inRE, post, postRS, postRE);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};