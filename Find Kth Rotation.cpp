class Solution {
  public:
    int findKRotation(vector<int> &nums) {
       int low = 0;
        int high = nums.size() - 1;
        int minEle = INT_MAX;
        int idx = 0;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high]) {
                if(nums[low] < minEle) {
                  minEle = nums[low];
                  idx = low;
                }
                break;
            }
            if(nums[low] <= nums[mid]){
               if(nums[low] < minEle) {
                  minEle = nums[low];
                  idx = low;
               }
               low = mid+1;
            } else {
                if(nums[mid] < minEle) {
                  minEle = nums[mid];
                  idx = mid;
               }
                high = mid-1;
            }
        }
        return idx;
    }
};
