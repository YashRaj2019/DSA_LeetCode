class Solution {
    public int sortPermutation(int[] nums) {
        int n = nums.length;
        int temp = -1;
        for(int i=0; i<n; i++){
            if(nums[i] != i){
                temp = temp & nums[i];
            }
        }
        if(temp == -1){
            return 0;
        }
        return temp;
    }
}