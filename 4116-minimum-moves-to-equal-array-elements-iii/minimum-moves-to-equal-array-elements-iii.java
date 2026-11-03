class Solution {
    public int minMoves(int[] nums) {
        Arrays.sort(nums);

        int n = nums.length;
        int count = 0;
        for(int num : nums){
            count += Math.abs(nums[n-1] - num);
        }

        return count;
    }
}