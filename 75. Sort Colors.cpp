class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;

        for(int i=0; i < nums.size(); i++){
            if(nums[i] == 0){
                count_zero++;
            } else if(nums[i] == 1){
                count_one++;
            } else {
                count_two++;
            }
        }
        int idx = 0;
        while(count_zero > 0){
            nums[idx] = 0;
            idx++;
            count_zero--;
        }
        while(count_one > 0){
            nums[idx] = 1;
            idx++;
            count_one--;
        }
        while(count_two > 0){
            nums[idx] = 2;
            idx++;
            count_two--;
        }
    }
};
