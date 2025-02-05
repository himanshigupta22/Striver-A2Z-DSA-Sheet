class Solution {
    static int matrixMultiplication(int arr[]) {
        // code here
        int n = arr.length;
        
        int[][] t = new int[n][n];
        
        for(int len = 2; len < n; len++){
            for(int i = 1; i < n-len+1; i++){
                int j = i + len - 1;
                t[i][j] = Integer.MAX_VALUE;
                
                for(int k = i; k < j; k++){
                    int cost = t[i][k] + t[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    
                    t[i][j] = Math.min(t[i][j], cost);
                }
            }
        }
        return t[1][n-1];
    }
}
