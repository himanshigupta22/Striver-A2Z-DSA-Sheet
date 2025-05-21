class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q;
        vector<int> mark(adj.size(), 0);
        
        for(int i=0; i < adj.size(); i++){
            if(adj[i].size() != 0){
                q.push(i); // sourceNode
                mark[i] = 1;
                break;
            }
        }
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            
            for(int i=0; i < adj[val].size(); i++){
                int ele = adj[val][i];
                if(mark[ele] == 0){
                    q.push(ele);
                    mark[ele] = 1;
                }
            }
            ans.push_back(val);
        }
        
        return ans;
    }
};
