class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;

        int[][] dp = new int[n+1][amount+1];

        for(int j=0; j<=amount; j++){
            dp[0][j] = (int) 1E9;
        }

        for(int i=1; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(j-coins[i-1]>=0){
                    dp[i][j] = Math.min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount] >= (int) 1E9 ? -1 : dp[n][amount];
    }
}

// Top-down approach : memoization

// class Solution {

//     public int helper(int n, int amount, int[] coins, int[][] dp){
//         if(amount==0){
//             return 0;
//         }

//         if(n==0 || amount < 0){
//             return (int) 1E9;
//         }

//         if(dp[n][amount] != -1){
//             return dp[n][amount];
//         }

//         return dp[n][amount] =  Math.min(helper(n-1, amount, coins, dp), 1+helper(n, amount-coins[n-1], coins, dp));
//     }

//     public int coinChange(int[] coins, int amount) {
//         int n = coins.length;

//         int[][] dp = new int[n+1][amount+1];
//         for(int i=0; i<=n; i++){
//             Arrays.fill(dp[i], -1);
//         }

//         int ans = helper(n, amount, coins, dp);

//         return ans >= (int) 1E9 ? -1 : ans;
//     }
// }