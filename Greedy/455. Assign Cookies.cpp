
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0, j=0;
        int count=0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                count++;
                i++;
            } 
            j++;
        }
        return i;
    }
};
