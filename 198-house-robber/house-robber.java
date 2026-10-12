class Solution {
    public int rob(int[] nums) {
        int n = nums.length;

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return Math.max(nums[0], nums[1]);
        }
        
        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            int curr = Math.max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}

// class Solution {
//     public int rob(int[] nums) {
//         int n = nums.length;
//         int[] dp = new int[n];
        
//         if(n==1){
//             return nums[0];
//         }
//         if(n==2){
//             return Math.max(nums[0], nums[1]);
//         }

//         dp[0] = nums[0];
//         dp[1] = Math.max(nums[0], nums[1]);

//         for(int i=2; i<n; i++){
//             dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
//         }

//         return dp[n-1];
//     }
// }


// class Solution {
//     public int helper(int i, int[] arr, int[] dp){

//         if(i==0){
//             return arr[0];
//         }
//         if(i==1){
//             return Math.max(arr[0], arr[1]);
//         }

//         if(dp[i] != -1){
//             return dp[i];
//         }

//         return dp[i] = Math.max(arr[i] + helper(i-2, arr, dp), helper(i-1, arr, dp));
//     }
//     public int rob(int[] nums) {
//         int n = nums.length;
//         int[] dp = new int[n];
//         Arrays.fill(dp, -1);
//         return helper(n-1, nums, dp);
//     }
// }

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