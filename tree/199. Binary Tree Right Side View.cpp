class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mpp;
        queue<pair<int,TreeNode*>> q; // horizontal, node
        vector<int> ans;

        if(root == NULL) return ans;
        
        q.push({0,root});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            TreeNode* temp = p.second;
            int horizontal = p.first;
            
            if(temp->left){
                q.push({horizontal+1,temp->left});
            }
            if(temp->right){
                q.push({horizontal+1,temp->right});
            }
            mpp[horizontal] = temp->val;
        }
        for(auto e:mpp){
            ans.push_back(e.second);
        }
        
        return ans;
    }
};
