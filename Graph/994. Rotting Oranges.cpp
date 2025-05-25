class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total_count = 0;
        int count = 0;
        int time = 0;
        queue<pair<int,int>> q;

        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(grid[i][j] != 0) total_count++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        count = q.size(); // initially rotten
        if (total_count == 0 || total_count == count) return 0; 

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
            int size = q.size();
            bool isRotten = false;

            for(int i=0; i < size; i++){
                pair<int,int> temp = q.front();
                q.pop();
                int row = temp.first;
                int col = temp.second;

                for(int j=0; j < 4; j++){
                   int r = row + directions[j].first;
                   int c = col + directions[j].second;
                   
                   if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
                      grid[r][c] = 2;
                      q.push({r,c});
                      count++;
                      isRotten = true;
                   }
                }
            }
            if(isRotten) time++;
        }
        if(total_count == count) return time;
        else return -1;
    }
};
