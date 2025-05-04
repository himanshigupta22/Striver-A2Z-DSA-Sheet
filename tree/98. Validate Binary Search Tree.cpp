class Solution {
public:

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> arr;
        TreeNode* node = root;
        TreeNode* prev = NULL;

        while(true){
           if(node != NULL){
              st.push(node);;
              node = node->left;
           } else {
              if(st.empty()) break;
              node = st.top();
              st.pop();
              if(prev != NULL && prev->val >= node->val) return false;
              prev = node;
              node = node->right;
           }
        }
        return true;
    }
};
