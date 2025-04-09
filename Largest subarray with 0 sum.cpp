class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        int k = 0;
        
        unordered_map<int, int> mpp;
        long long sum = 0;
        int maxlen = 0;
        
        for(int i=0; i < n; i++){
            sum += arr[i];
            
            if(sum == k){
                maxlen = i+1;
            }
            
            int rem = sum-k;
            if(mpp.find(rem) != mpp.end()){
                maxlen = max(maxlen, i - mpp[rem]);
            }
            
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxlen;
    }
};
