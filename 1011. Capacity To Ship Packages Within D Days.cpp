class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high;
        for(int ele : weights){
            high += ele;
        }

        while(low <= high){
            int mid = (low + high)/ 2;
            int cnt_days = 0;
            int capacity = 0;
            for(int ele : weights){
              if(capacity + ele <= mid){
                capacity += ele;
              } else {
                cnt_days++;
                capacity = ele;
              }
            }
            cnt_days++;
            if(cnt_days <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
