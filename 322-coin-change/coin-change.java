class Solution {

    public int helper(int n, int amount, int[] coins, int[][] dp){
        if(amount==0){
            return 0;
        }

        if(n==0 || amount < 0){
            return (int) 1E9;
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        return dp[n][amount] =  Math.min(helper(n-1, amount, coins, dp), 1+helper(n, amount-coins[n-1], coins, dp));
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;

        int[][] dp = new int[n+1][amount+1];
        for(int i=0; i<=n; i++){
            Arrays.fill(dp[i], -1);
        }

        int ans = helper(n, amount, coins, dp);

        return ans == (int) 1E9 ? -1 : ans;
    }
}