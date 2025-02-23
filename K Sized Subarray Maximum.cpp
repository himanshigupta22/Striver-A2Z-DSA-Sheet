 vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        list<int> ls;
        
        int i = 0, j = 0;
        
        while(j < arr.size()){
            while(ls.size() > 0 && ls.back() < arr[j]){
                ls.pop_back();
            }
            ls.push_back(arr[j]);
            
            if(j-i+1 < k){
                j++;
            } else if(j-i+1 == k){
                ans.push_back(ls.front());
                if(ls.front() == arr[i]){
                    ls.pop_front();
                }
                i++; j++;
            }
        }
        return ans;
    }
