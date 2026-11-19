class Solution {

    public int helper(int n, int amount, int coins[], int[][] dp){
        if(amount == 0){
            return 1;
        }

        if(n==0 || amount < 0){
            return 0;
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        int notTake = helper(n-1, amount, coins, dp);
        int take = helper(n, amount-coins[n-1], coins, dp);
        return  dp[n][amount] =  take + notTake;

    }

    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] dp = new int[n+1][amount+1];
        for(int i=0; i<=n; i++){
            Arrays.fill(dp[i], -1);
        }
        return helper(n, amount, coins, dp);
    }
}
// class Solution {

//     public int helper(int n, int amount, int coins[]){
//         if(amount == 0){
//             return 1;
//         }

//         if(n==0 || amount < 0){
//             return 0;
//         }

//         int notTake = helper(n-1, amount, coins);
//         int take = helper(n, amount-coins[n-1], coins);
//         return  take + notTake;

//     }

//     public int change(int amount, int[] coins) {
//         int n = coins.length;
//         return helper(n, amount, coins);
//     }
// }