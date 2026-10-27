class Solution {
    public void moveZeroes(int[] nums) {

        // int arr[] = new int[nums.length];
        // int j = 0;

        // for(int i=0; i<nums.length; i++){
        //     if(nums[i] != 0){
        //         arr[j] = nums[i];
        //         j++;
        //     }

        // }

        // for(int i=0; i<arr.length; i++){
        //     nums[i] = arr[i];
        // }

        int j = 0;
        for(int i=0; i<nums.length; i++){
           if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
           }
        }
    }
}