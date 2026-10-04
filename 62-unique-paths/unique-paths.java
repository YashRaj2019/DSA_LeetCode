class Solution {

    public int solve(int m, int n, int[][] dp){
        if(m== 1 || n==1){
            return 1;
        }

        if(dp[m][n] != 0){
            return dp[m][n];
        }

        dp[m][n] = solve(m, n-1, dp) + solve(m-1, n, dp);
        return dp[m][n];
    }

    public int uniquePaths(int m, int n) {

        // if(m == 1 || n == 1){  // method 1 : using recursion : tle
        //     return 1;
        // }
        // return uniquePaths(m, n-1) + uniquePaths(m-1, n);

        int[][] dp = new int[m+1][n+1];  // if int[][] dp = new int dp[m][n], then 
                                        // if(dp[m][n] != 0){   this can be replaced by m-1 and n-1 in above function
                                        //      return dp[m][n];
                                        // }
                                    
        return solve(m, n, dp);
    }
}