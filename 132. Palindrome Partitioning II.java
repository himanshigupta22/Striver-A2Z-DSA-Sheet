class Solution {
    boolean isPalindrome(String s, int i, int j){
        while(i < j){
           if(s.charAt(i) != s.charAt(j)){
            return false;
           }
           i++; j--;
        }
        return true;
    }

    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n+1];
        dp[n] = 0;

        for(int i = n-1; i >= 0; i--){
            int minCost = Integer.MAX_VALUE;

            for(int k = i; k <= n-1; k++){
                if(isPalindrome(s, i, k)){
                    int cost = 1 + dp[k+1];
                    minCost = Math.min(cost, minCost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
}
