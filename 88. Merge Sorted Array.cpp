class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // gap method
        int len = m+n;
        int gap = len/2 + len%2;

        while(gap > 0){
            int left = 0;
            int right = left + gap;

            while(right < m+n){
                // nums1, nums2
                if(left < m && right >= m){
                   if(nums1[left] > nums2[right-m]){
                    swap(nums1[left], nums2[right-m]);
                   }
                } // nums1
                else if(right < m){
                    if(nums1[left] > nums1[right]){
                        swap(nums1[left], nums1[right]);
                    }
                } // nums2
                else if(left >= m){
                    if(nums2[left-m] > nums2[right-m]){
                        swap(nums2[left-m], nums2[right-m]);
                    }
                }
                left++; right++;
            }
            if(gap == 1) break;
            gap = gap/2 + gap%2;
        }
        for(int i=m; i < len; i++){
            nums1[i] = nums2[i-m];
        }
    }
};
