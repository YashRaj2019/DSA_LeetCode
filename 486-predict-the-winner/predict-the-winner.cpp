class Solution {
public:

    int solve(vector<int>&nums, int i, int j){

        // only one number is left
        if(i == j) {
            return nums[i];
        }

        // pick the left number
        int left = nums[i] - solve(nums, i+1, j);

        // pick the right element
        int right = nums[j] - solve(nums, i, j-1);

        // choose the better option
        return max(left, right);

    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1) >= 0;

    }
};