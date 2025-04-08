class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int fr = 0, fc = 0;
        int lr = m-1, lc = n-1;

        while(true){
            // top
            for(int c = fc; c <= lc; c++){
              ans.push_back(matrix[fr][c]);
            }
            fr++;
            if(fr > lr) break;

            // right
            for(int r = fr; r <= lr; r++){
              ans.push_back(matrix[r][lc]);
            }
            lc--;
            if(fc > lc) break;

            // bottom
            for(int c = lc; c >= fc; c--){
               ans.push_back(matrix[lr][c]);
            }
            lr--;
            if(fr > lr) break;

            // left 
            for(int r = lr; r >= fr; r--){
               ans.push_back(matrix[r][fc]);
            }
            fc++;
            if(fc > lc) break;
        }

        return ans;
    }
};
