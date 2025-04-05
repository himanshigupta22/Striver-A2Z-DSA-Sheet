class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=n-1, j=n-1;
        string word = "";
        string ans = "";

        while(i >= 0){
            while(j >= 0 && s[j] == ' '){
                j--;
            }
            if(j == -1) break;
            i = j;
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            for(int k=i+1; k <= j; k++){
                word += s[k];
            }
            j = i;
            ans += word;
            ans += " ";
            word = "";
        }
        ans.pop_back();
        return ans;
    }
};
