class Solution {

    public int helper(int i, int sum, int[] nums, int target) {

        if (i == nums.length) {
            return sum == target ? 1 : 0;
        }

        int add = helper(i + 1, sum + nums[i], nums, target);
        int subtract = helper(i + 1, sum - nums[i], nums, target);

        return add + subtract;
    }

    public int findTargetSumWays(int[] nums, int target) {
        return helper(0, 0, nums, target);
    }
}