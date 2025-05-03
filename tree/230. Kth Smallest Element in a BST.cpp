class Solution {
public:
    int inorderTraversal(TreeNode* root, int k) {
        int cnt=1;
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;

        while(true){
           if(node != NULL){
              st.push(node);
              node = node->left;
           } else {
              if(st.empty()) break;
              node = st.top();
              st.pop();
              if(cnt == k) return node->val;
              cnt++;
              node = node->right;
           }
        }
        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
    }
};
