class Solution {
    public int helper(int i, int[] arr, int[] dp){

        if(i==0){
            return arr[0];
        }
        if(i==1){
            return Math.max(arr[0], arr[1]);
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = Math.max(arr[i] + helper(i-2, arr, dp), helper(i-1, arr, dp));
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return helper(n-1, nums, dp);
    }
}

// class Solution {
//     public int helper(int i, int[] arr){

//         if(i==0){
//             return arr[0];
//         }
//         if(i==1){
//             return Math.max(arr[0], arr[1]);
//         }

//         return Math.max(arr[i] + helper(i-2, arr), helper(i-1, arr));
//     }
//     public int rob(int[] nums) {
//         int n = nums.length;
//         return helper(n-1, nums);
//     }
// }