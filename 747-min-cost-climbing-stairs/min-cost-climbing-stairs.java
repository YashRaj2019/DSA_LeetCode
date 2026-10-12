class Solution {
    // Mthod 1: Recursion
    public int minCost(int i, int[] arr, int[] dp){

        if(i<=1){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] =  Math.min(minCost(i-1, arr, dp) + arr[i-1], minCost(i-2, arr, dp) + arr[i-2]);
    }

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return minCost(n, cost, dp);
    }
}


// class Solution {
//     // Mthod 1: Recursion
//     public int minCost(int i, int[] arr){

//         if(i<=1){
//             return 0;
//         }

//         return Math.min(minCost(i-1, arr) + arr[i-1], minCost(i-2, arr) + arr[i-2]);
//     }

//     public int minCostClimbingStairs(int[] cost) {
//         int n = cost.length;
//         return minCost(n, cost);
//     }
// }