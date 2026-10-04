// class Solution {
//     public int search(int[] nums, int target) {
//        int low = 0, high = nums.length-1;

//        while(low <= high){
//            int mid = low + (high - low) / 2;

//            if(nums[mid] == target){
//                return mid;
//            }

//            else if(nums[mid] < target){
//                low = mid + 1;
//            }
//            else{
//                high = mid - 1;
//            }
//        }
//        return -1; 
//     }
// }

// Method 2:  using recursion
class Solution {

    public int solve(int nums[], int target, int lo, int hi){

        if(lo > hi){
            return -1;
        }

        int mid = lo + (hi - lo)/2;

        if(nums[mid] == target){
            return mid;
        }

        else if(nums[mid] < target){
            return solve(nums, target, mid+1, hi);
        }

        else{
            return solve(nums, target, lo, mid-1);
        }

    }

    public int search(int[] nums, int target) {
       int n = nums.length;
       return solve(nums, target, 0, n-1);
    }
}