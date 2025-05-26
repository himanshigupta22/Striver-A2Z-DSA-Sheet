class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];

        if(oldColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        vector<pair<int,int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};

        while(!q.empty()){
           auto temp = q.front(); 
           q.pop();

           for(int i=0; i < 4; i++){
              int r = temp.first + directions[i].first;
              int c = temp.second + directions[i].second;

              if(r >= 0 && c >= 0 && r < m && c < n && image[r][c] == oldColor){
                 image[r][c] = color;
                 q.push({r,c});
              }
           }
        }
        return image;
    }
};
