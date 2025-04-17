class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        int n = bt.size();
        int wt = 0;
        int total_wt = 0;
        
        for(int i=0; i < n-1; i++){
            wt += bt[i];
            total_wt += wt;
        }
        
        return total_wt/n;
    }
};
