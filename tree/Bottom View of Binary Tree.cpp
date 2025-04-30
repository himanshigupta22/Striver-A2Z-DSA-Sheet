class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
       
        map<int,int> mpp;
        queue<pair<int,Node*>> q; // vertical, node
        vector<int> ans;
        
        q.push({0,root});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            Node* temp = p.second;
            int vertical = p.first;
            
            if(temp->left){
                q.push({vertical-1,temp->left});
            }
            if(temp->right){
                q.push({vertical+1,temp->right});
            }
            mpp[vertical] = temp->data;
        }
        for(auto e:mpp){
            ans.push_back(e.second);
        }
        
        return ans;
    }
};
