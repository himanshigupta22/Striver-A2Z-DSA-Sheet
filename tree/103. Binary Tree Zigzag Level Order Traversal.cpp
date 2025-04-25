class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int> v(n,0);
            for(int i=0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
                (flag == 0) ? v[i] = temp->val : v[n-i-1] = temp->val;
            }
            ans.push_back(v);
            if(flag == 0) flag = 1;
            else flag = 0;
        }

        return ans;
    }
};
