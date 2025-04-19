
class Solution {
  public:
    static bool comparison(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int, int>> pr;
        int n = deadline.size();
        
        int maxi = 0;
        for(int i=0; i < n; i++){
            pr.push_back({deadline[i], profit[i]});
            maxi = max(maxi, deadline[i]);
        }
        
        sort(pr.begin(), pr.end(), comparison);
        
        vector<int> arr(maxi+1, -1);
        
        int countJob = 0, jobProfit = 0;
        
        for(int i=0; i < n; i++){
            for(int j = pr[i].first; j > 0; j--){
                if(arr[j] == -1){
                    arr[j] = i;
                    countJob++;
                    jobProfit += pr[i].second;
                    break;
                }
            }
        }
        
        return {countJob, jobProfit};
    }
};
