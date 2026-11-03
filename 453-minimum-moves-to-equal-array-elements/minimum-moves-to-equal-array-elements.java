class Solution {
    public int minMoves(int[] nums) {
        int min = Arrays.stream(nums).min().getAsInt();
        int count = 0;
        for(int num : nums){
            count += num-min;
        }
        return count;
    }
}