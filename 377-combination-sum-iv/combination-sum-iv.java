class Solution {
    public int combinationSum4(int[] nums, int target) {

        int[] dp = new int[target+1];

        dp[0] = 1;

        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.length; j++){
                if(i >= nums[j]){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
}
// class Solution {

//     public int helper(int target, int[] nums, int[] dp){
//         if(target == 0){
//             return 1;
//         }

//         if(dp[target] != -1){
//             return dp[target];
//         }
        
//         int count = 0;
//         for(int i=0; i<nums.length; i++){
//             if(target >= nums[i]){
//                 count += helper(target - nums[i], nums, dp);
//             }
//         }
//         return dp[target] =  count;
//     }

//     public int combinationSum4(int[] nums, int target) {

//         int[] dp = new int[target+1];
//         Arrays.fill(dp, -1);
//         return helper(target, nums, dp);
//     }
// }

// class Solution {

//     public int helper(int target, int[] nums){
//         if(target == 0){
//             return 1;
//         }
        
//         int count = 0;
//         for(int i=0; i<nums.length; i++){
//             if(target >= nums[i]){
//                 count += helper(target - nums[i], nums);
//             }
//         }
//         return count;
//     }

//     public int combinationSum4(int[] nums, int target) {

//         return helper(target, nums);
//     }
// }