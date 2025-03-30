class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int min_day = INT_MAX;
        int max_day = INT_MIN;
        int n = bloomDay.size();

        if(m*1L*k > n) return -1;

        for(int i=0; i < n; i++){
            min_day = min(min_day, bloomDay[i]);
            max_day = max(max_day, bloomDay[i]);
        }
        int low = min_day;
        int high = max_day;

        while(low <= high){
            int mid = (low + high)/2;
            int flower = 0;
            int bouquet = 0;
            for(int i=0; i < n; i++){
                if(bloomDay[i] <= mid){
                   flower++;
                   if(flower == k){
                    bouquet++;
                    flower = 0;
                   }
                } else {
                    flower = 0;
                }
            } 
            if(bouquet >= m) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
