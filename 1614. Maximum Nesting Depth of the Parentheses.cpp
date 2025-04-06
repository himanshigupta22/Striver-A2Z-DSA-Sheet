class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int value = 0;

        for(int i=0; i < s.length(); i++){
            if(s[i] == '('){
                value += 1;
                cnt = max(cnt, value);
            } else if(s[i] == ')') {
                value -= 1;
            }
        }
        return cnt;
    }
};
