// class Solution {

//     public int helper(int i, int sum, int[] nums, int target) {

//         if (i == nums.length) {
//             return sum == target ? 1 : 0;
//         }

//         int add = helper(i + 1, sum + nums[i], nums, target);
//         int subtract = helper(i + 1, sum - nums[i], nums, target);

//         return add + subtract;
//     }

//     public int findTargetSumWays(int[] nums, int target) {
//         return helper(0, 0, nums, target);
//     }
// }


class Solution {
    
    public int helper(int i, int target, int[] arr){
        
        if(i==arr.length){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int sum = helper(i+1, target-arr[i], arr);
        int sub = helper(i+1, target+arr[i], arr);
        
        return sum + sub;
    }
    public int findTargetSumWays(int[] arr, int target) {
        // code here
        return helper(0, target, arr);
        
    }
}