class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int max_k = 0;
        for(int i=0; i < piles.size(); i++){
           max_k = max(max_k, piles[i]);
        }

        int low = 1;
        int high = max_k;

        while(low <= high){
            int mid = (low + high)/2;
            long long calculated_hrs = 0;
            for(int i=0; i < piles.size(); i++){
                calculated_hrs += (piles[i] + mid - 1) / mid; // Equivalent to ceil(piles[i] / mid)
            }
            if(calculated_hrs <= h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
