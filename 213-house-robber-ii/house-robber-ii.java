class Solution {
    int Robber(int start, int end, int[] arr, int[] dp){

        if(start > end){
            return 0;
        }

        if(dp[end] != -1){
            return dp[end];
        }

        int pick = arr[end] + Robber(start, end-2, arr, dp);
        int skip = Robber(start, end-1, arr, dp);

        return dp[end] = Math.max(pick, skip);
    }
    public int rob(int[] nums) {
       int n = nums.length;

       if(n==1){
           return nums[0];
       }

       int[] dp1 = new int[n];
       int[] dp2 = new int[n];

       Arrays.fill(dp1, -1);
       Arrays.fill(dp2, -1);

        int case1 = Robber(0, n-2, nums, dp1);
        int case2 = Robber(1, n-1, nums, dp2);

        return Math.max(case1, case2);
    }
}
// class Solution {
//     int Robber(int start, int end, int[] arr){

//         if(start > end){
//             return 0;
//         }

//         int pick = arr[end] + Robber(start, end-2, arr);
//         int skip = Robber(start, end-1, arr);

//         return Math.max(pick, skip);
//     }
//     public int rob(int[] nums) {
//        int n = nums.length;

//        if(n==1){
//            return nums[0];
//        }

//         int case1 = Robber(0, n-2, nums);
//         int case2 = Robber(1, n-1, nums);

//         return Math.max(case1, case2);
//     }
// }