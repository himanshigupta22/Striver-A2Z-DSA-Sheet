class Solution {
public:
    
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
    
        for(int i=0; i < n-2; i++){
            vector<int> freq(26, 0);
            for(int j=i; j < n; j++){
                freq[s[j]-'a']++;
                if(i+2 <= j){
                   int mostFreq = INT_MIN;
                   int leastFreq = INT_MAX;

                   for(int k=0; k < 26; k++){
                    if(freq[k] > 0){
                        mostFreq = max(mostFreq, freq[k]);
                        leastFreq = min(leastFreq, freq[k]);
                    }
                   }
                   sum += (mostFreq - leastFreq);
                }
            }
        }
         return sum;
    }
};
