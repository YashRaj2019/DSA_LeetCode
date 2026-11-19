class Solution {

    public int helper(int n, int i, int[][] dp){
        if(n==0){
            return 0;
        }

        if(i * i > n){
            return 100000;
        }

        if(dp[n][i] != -1){
            return dp[n][i];
        }

        int take = 1 + helper(n - i * i, i, dp);
        int notTake = helper(n, i+1, dp);

        return dp[n][i] = Math.min(take, notTake);
    }

    public int numSquares(int n) {
        int[][] dp = new int[n+1][(int)Math.sqrt(n)+2];
        for(int i=0; i<=n; i++){
            Arrays.fill(dp[i], -1);
        }
        return helper(n, 1, dp);
    }
}