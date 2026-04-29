class Solution {
public:

    int Robber(int index, vector<int>& nums, vector<int>& dp){
        if(index==0){ // if only one house is present
            return nums[0];
        }

        if(index==1){  // only two houses are present
            return max(nums[0], nums[1]);  
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // more than two houses are present
        return dp[index] = max((nums[index] + Robber(index-2, nums, dp)), Robber(index-1, nums, dp));

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return Robber(n-1, nums, dp);
    }
};