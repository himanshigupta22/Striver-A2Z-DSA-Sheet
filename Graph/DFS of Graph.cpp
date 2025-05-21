class Solution {
  public:
    void helper_func(int node, vector<vector<int>>& adj, vector<int> &ans, vector<int> &visited){
        visited[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
               helper_func(it, adj, ans, visited); 
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<int> visited(adj.size(), 0);
        
        helper_func(0, adj, ans, visited);
        
        return ans;
    }
};
