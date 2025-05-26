class Solution {
  public:
  
    // DFS helper
    bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adjLs) {
        visited[node] = 1;
        for (int temp : adjLs[node]) {
            if (visited[temp] == 0) {
                if (dfs(temp, node, visited, adjLs)) {
                    return true;
                }
            } else if (temp != parent) {
                // A visited neighbor not equal to parent means cycle
                return true;
            }
        }
        return false;
    }
   
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjLs(V);
        
        // Building the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            adjLs[edges[i][0]].push_back(edges[i][1]);
            adjLs[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(V, 0);

        // Handle disconnected components
        for (int start = 0; start < V; start++) {
            if (!visited[start]) {
                if (dfs(start, -1, visited, adjLs)) {
                    return true;
                }
            }
        }

        return false;
    }
};
