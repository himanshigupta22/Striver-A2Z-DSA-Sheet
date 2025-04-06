class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;

        for(int i=0; i < s.length(); i++){
            mpp[s[i]]++;
        }
        vector<pair<char, int>> freqVec(mpp.begin(), mpp.end());
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans = "";
        for(int i=0; i < freqVec.size(); i++){
            for(int j=0; j < freqVec[i].second; j++){
                ans += freqVec[i].first;
            }
        }
      
        return ans;
    }
};
