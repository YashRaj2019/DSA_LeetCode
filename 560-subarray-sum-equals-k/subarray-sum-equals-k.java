// class Solution {
//     public int subarraySum(int[] nums, int k) {
//         HashMap<Integer, Integer> map = new HashMap<>();
//         map.put(0, 1);

//         int sum = 0, count = 0;

//         for(int ele : nums){
//             sum += ele;

//             if(map.containsKey(sum - k)){
//                 count += map.get(sum - k);
//             }

//             map.put(sum, map.getOrDefault(sum, 0) + 1);
//         }

//         return count;
//     }
// }


class Solution {
    public int subarraySum(int[] nums, int k) {
        return count(nums, k, 0, 0);
    }

    int count(int[] nums, int k, int start, int sum) {
        if (start == nums.length) return 0;

        int ans = 0;
        int currSum = 0;

        for (int i = start; i < nums.length; i++) {
            currSum += nums[i];

            if (currSum == k) {
                ans++;
            }
        }

        return ans + count(nums, k, start + 1, 0);
    }
}