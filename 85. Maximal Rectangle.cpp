class Solution {
public:
    vector<int> NearestSmallestRight(vector<int> &arr){
        stack<pair<int,int>> st;
        vector<int> v;
        for(int i = arr.size()-1; i >= 0; i--){
           while(st.size() > 0 && st.top().first >= arr[i]){
            st.pop();
           }
           if(st.size() == 0){
            v.push_back(arr.size());
           } else {
            v.push_back(st.top().second);
           }
           st.push({arr[i],i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
    vector<int> NearestSmallestLeft(vector<int> &arr){
        stack<pair<int,int>> st;
        vector<int> v;
        for(int i = 0; i < arr.size(); i++){
           while(st.size() > 0 && st.top().first >= arr[i]){
            st.pop();
           }
           if(st.size() == 0){
            v.push_back(-1);
           } else {
            v.push_back(st.top().second);
           }
           st.push({arr[i],i});
        }
        return v;
    }
    int MaximumAreaHistogram(vector<int> &arr){
        vector<int> right = NearestSmallestRight(arr);
        vector<int> left = NearestSmallestLeft(arr);

        int maxi = 0;
        for(int i=0; i < arr.size(); i++){
            int area = arr[i] * (right[i]-left[i]-1);
            maxi = max(maxi, area); 
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        for(int j=0; j < matrix[0].size(); j++){
            v.push_back(matrix[0][j] - '0');
        }

        int maxi = MaximumAreaHistogram(v);

        for(int i=1; i < matrix.size(); i++){
         
            for(int j=0; j < matrix[0].size(); j++){
                if(matrix[i][j] != '0'){
                    v[j] += 1;
                } else {
                    v[j] = 0;
                }
            }
            maxi = max(maxi, MaximumAreaHistogram(v));
        }
        return maxi;
    }
    
};
