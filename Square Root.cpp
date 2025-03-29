class Solution {
    int floorSqrt(int n) {
        // Your code here
        int low = 1;
        int high = n;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(mid*mid == n) return mid;
            if(mid*mid > n) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
}
