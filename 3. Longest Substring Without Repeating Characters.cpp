class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int len = 0;
        vector<int> mpp(256, -1);

        while(right < s.length()){
          if(mpp[s[right]] != -1){
            // for test case [abba]
            left = max(mpp[s[right]] + 1, left);
          }
          // storing index of current char
          mpp[s[right]] = right;
          len = max(len, right-left+1);
          right++;
        }
        return len;
    }
};
