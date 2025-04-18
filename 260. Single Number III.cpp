class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        int n = nums.size();
        int b1 = 0, b2 = 0;

        for(int i=0; i < n; i++){
            xorr ^= nums[i];
        }
        int rightmostOne = (xorr & (xorr-1)) ^ xorr;

        for(int i=0; i < n; i++){
           if(nums[i] & rightmostOne){
             b1 ^= nums[i];
           } else {
             b2 ^= nums[i];
           }
        }

        return {b1, b2};
    }
};
