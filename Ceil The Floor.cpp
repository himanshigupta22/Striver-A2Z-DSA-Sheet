class Solution {
  public:
     int findFloor(vector<int>& arr, int k) {

        // Your code here
        int ans = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[mid] <= k){
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return (ans != -1)? arr[high] : ans;
    }
    
     int findCeil(vector<int>& arr, int k) {

        // Your code here
        int ans = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[mid] >= k){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return (ans != -1)? arr[low] : ans;
    }
    
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        
        sort(arr.begin(), arr.end());
        
        int fl = findFloor(arr, x);
        int cl = findCeil(arr, x);
        
        return {fl, cl};
        
    }
};
