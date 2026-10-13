class Solution {
    public long maxAlternatingSum(int[] nums) {

        int n = nums.length;
        long[]  square = new long[n];

        for(int i=0; i<nums.length; i++){
            square[i] = (long) nums[i] * nums[i];
        }

        Arrays.sort(square);

        long sum = 0;
        for(int i=0; i<n; i++){
            if(i < n/2){
                sum -= square[i];
            }
            else{
                sum += square[i];
            }
        }
        return sum;
    }
}