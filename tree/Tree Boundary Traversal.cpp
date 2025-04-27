class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        Node* node = root;
        if(!(node->right == NULL && node->left == NULL))
            ans.push_back(node->data);
        
        node = node->left;
        
        // left boundary
        while(node != NULL){
            if(!(node->right == NULL && node->left == NULL))
            ans.push_back(node->data);
            
            if(node->left) node = node->left;
            else node = node->right;
        }
        
        // leaf nodes - preorder traversal
        stack<Node*>st;
        st.push(root);
        
        while(!st.empty()){
            node = st.top();
            st.pop();
            if(node->left == NULL && node->right == NULL) ans.push_back(node->data);
            
            if(node->right != NULL) st.push(node->right);
            if(node->left != NULL) st.push(node->left);
        }
        
        
        // right boundary
        node = root->right;
        vector<int> temp;
        
        while(node != NULL){
            if(!(node->right == NULL && node->left == NULL))
            temp.push_back(node->data);
            
            if(node->right) node = node->right;
            else node = node->left;
        }
        
        for(int i=temp.size()-1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
};
