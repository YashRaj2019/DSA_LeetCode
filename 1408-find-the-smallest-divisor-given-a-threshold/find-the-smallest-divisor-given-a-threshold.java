class Solution {
    public int smallestDivisor(int[] nums, int threshold) {

        int low = 1;
        int high = Arrays.stream(nums).max().getAsInt();

        while(low <= high){
            int mid = low + (high - low) / 2;

            int sum = 0;
            for(int ele : nums){
                sum += (ele + mid - 1) / mid;
            }
            if(sum <= threshold){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
}