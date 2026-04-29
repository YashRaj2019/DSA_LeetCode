class Solution {
public:
    int Robber(vector<int> &nums, int start, int end){
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]

        for(int i=start; i<= end; i++){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // edge case
        if(n==0){
            return 0;
        }

        if(n==1){
            return nums[0];
        }

        // case 1 : exclude last
        int case1 = Robber(nums, 0, n-2);

        // case 2 : exclude first
        int case2 = Robber(nums, 1, n-1);

        return max(case1, case2);
        
    }
};