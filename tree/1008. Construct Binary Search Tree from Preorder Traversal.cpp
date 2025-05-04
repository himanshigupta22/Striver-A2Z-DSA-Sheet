class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1; i < preorder.size(); i++){
          TreeNode* node = root;

          while(true){
            if(preorder[i] < node->val){
                if(node->left == NULL){
                    node->left = new TreeNode(preorder[i]);
                    break;
                }
                node = node->left;
            } else {
                if(node->right == NULL){
                    node->right = new TreeNode(preorder[i]);
                    break;
                }
                node = node->right;
            }
          }
        }
        return root;
    }
};
