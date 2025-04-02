class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majEle1 = INT_MIN, majEle2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();

        for(int i=0; i < nums.size(); i++){
            if(majEle1 == nums[i]){
                cnt1++;
            } else if(majEle2 == nums[i]){
                cnt2++;
            } 
            else if(cnt1 == 0) {
                majEle1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                majEle2 = nums[i];
                cnt2++;
            }else {
                cnt1--; cnt2--;
            }
        }
        vector<int> ans;
        int c1 = 0, c2 = 0;
        for(int i=0; i < n; i++){
            if(majEle1 == nums[i]) c1++;
            if(majEle2 == nums[i]) c2++;
        }

        if(c1 > n/3) ans.push_back(majEle1);
        if(c2 > n/3) ans.push_back(majEle2);

        return ans;
    }
};
