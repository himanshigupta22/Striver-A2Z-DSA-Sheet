class BSTIterator {
private:
    stack<TreeNode*> myStack;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {  // o(1) space - o(H)
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    void pushAll(TreeNode* node){
        while(node != NULL){
            myStack.push(node);
            node = node->left;
        }
    }
};
