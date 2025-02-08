class Solution {
    void func(int i, String s, List<String> path, List<List<String>> res){
        if(i == s.length()){
            res.add(new ArrayList<> (path));
            return;
        }
        for(int k = i; k <= s.length()-1; k++){
            if(isPalindrome(s, i, k)){
                path.add(s.substring(i, k+1));
                func(k+1, s, path, res);
                path.remove(path.size()-1);
            }
        }
    }

    public boolean isPalindrome(String s, int i, int j){
        while(i < j ){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    public List<List<String>> partition(String s) {
        List<String> path = new ArrayList<> ();
        List<List<String>> res = new ArrayList<> ();

        func(0, s, path, res);
        return res;
    }
}
