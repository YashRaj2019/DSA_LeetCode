class Solution {

    public int helper(int idx, int prev, int[] arr, int[][] dp){
        if(idx==arr.length){
            return 0;
        }

        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }

        int skip = helper(idx+1, prev, arr, dp);

        if(prev != -1 && arr[idx] <= arr[prev]){
            return skip;
        }

        int pick = 1 + helper(idx+1, idx, arr, dp);

        return dp[idx][prev+1] =  Math.max(pick, skip);
    }

    public int lengthOfLIS(int[] nums) {

        int n = nums.length;
        int[][] dp = new int[n][n+1];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }

        return helper(0, -1, nums, dp);
    }
}