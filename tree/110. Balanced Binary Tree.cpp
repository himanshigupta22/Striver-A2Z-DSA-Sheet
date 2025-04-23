class Solution {
public:
    int checkBalanced(TreeNode* root){
        if(root == NULL) return 0;

        int lh = checkBalanced(root->left);
        if(lh == -1) return -1;

        int rh = checkBalanced(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(checkBalanced(root) == -1) return false;
        return true;
    }
};
