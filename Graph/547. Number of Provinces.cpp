class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int> &visited){
        visited[node] = 1;
        for(auto it: adjLs[node]){
            if(!visited[it]){
               dfs(it, adjLs, visited); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n+1, 0);
        int cnt = 0;
        vector<vector<int>> adjLs(n+1);

        // to change adjacency matrix to list 
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i+1].push_back(j+1); 
                    adjLs[j+1].push_back(i+1); 
                }
            }
        }
        
        for(int i=1; i < visited.size(); i++){
           if(visited[i] == 0){
              dfs(i, adjLs, visited);
              cnt++;
           }
        }
        return cnt;
    }
};
