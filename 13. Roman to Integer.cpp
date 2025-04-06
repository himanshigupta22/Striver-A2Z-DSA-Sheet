class Solution {
public:
    
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int idx = 0;
        int ans = 0;

        while(idx < s.length()-1){
          if(mpp[s[idx]] < mpp[s[idx+1]]){
            ans -= mpp[s[idx]];
          } else {
            ans += mpp[s[idx]];
          }
          idx++;
        }
        ans += mpp[s[idx]];

        return ans;
    }
};
