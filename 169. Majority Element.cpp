class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int majEle = nums[0];
       int cnt = 1;

       for(int i=1; i < nums.size(); i++){
        if(cnt == 0) {
            majEle = nums[i];
            cnt++;
        }else if(majEle == nums[i]){
            cnt++;
        } else {
            cnt--;
        }
       }

       return majEle;
    }
};
