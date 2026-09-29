class Solution {
    public int[] singleNumber(int[] nums) {
        int ans = 0;
        for(int i=0; i<nums.length; i++){
            ans ^= nums[i];
        }

        int mask = (ans &(ans -1)) ^ ans; // rightmost set bit mask

        int a = 0, b = 0;

        for(int i=0; i<nums.length; i++){
            if((nums[i] & mask) != 0){
                a ^= nums[i];
            }

            else{
                b ^= nums[i];
            }
        }

        if( a < b){
            return new int[] {a, b};
        }

        return new int[] {b, a};
    }
}