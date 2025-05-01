class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* node = root;
        TreeNode* temp;

        if(root == NULL) return newNode;

        while(node != NULL){
            temp = node;
            if(node->val > val) node = node->left;
            else node = node->right;
        }
        if(temp->val > val) temp->left = newNode;
        else temp->right = newNode;

        return root;
    }
};
