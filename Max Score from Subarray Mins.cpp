class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        
        int i=0, j=1;
        int res = 0;
        int sum = 0;
        
        while(j < arr.size()){
            sum = arr[i] + arr[j];
            res = max(res, sum);
            i++; j++;
        }
        
        return res;
    }
};
