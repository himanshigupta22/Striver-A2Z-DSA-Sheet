class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int check = 0;
        for(int i=0; i < s.length(); i++){
            if(s[i] == '(') check -= 1;
            else check += 1;
            if((s[i] == '(' && check == -1)||(s[i] == ')' && check == 0)){
                ans += s[i];
            }          
        }
        return ans;
    }
};
