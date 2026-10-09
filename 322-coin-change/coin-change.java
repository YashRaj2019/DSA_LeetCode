// class Solution {

//     // method 1 : recursive tle
//     public int helper(int i, int amount, int[] coins){

//         if(amount == 0){
//             return 0;
//         }

//         if(i==coins.length || amount < 0){
//             return 1000000;
//         }

//         int pick = 1 + helper(i, amount - coins[i], coins);
//         int skip = helper(i + 1, amount, coins);

//         return Math.min(pick, skip);
//     }

//     public int coinChange(int[] coins, int amount) {
        
//         int ans = helper(0, amount, coins);

//         return ans == 1000000 ? -1 : ans; 
//     }
// }

class Solution {

    // method 1 : recursive tle
    public int helper(int i, int amount, int[] coins, int[][] dp){

        if(amount == 0){
            return 0;
        }

        if(i==coins.length || amount < 0){
            return 1000000;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int pick = 1 + helper(i, amount - coins[i], coins, dp);
        int skip = helper(i + 1, amount, coins, dp);

        return dp[i][amount] = Math.min(pick, skip);
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] dp = new int[n][amount+1];
        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }
        
        int ans = helper(0, amount, coins, dp);
        return ans == 1000000 ? -1 : ans; 
    }
}