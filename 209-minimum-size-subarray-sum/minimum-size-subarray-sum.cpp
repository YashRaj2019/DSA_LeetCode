class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        // // method 1
        // int left = 0;
        // int sum = 0;
        // int minLen = INT_MAX;

        // for(int right=0;right<nums.size();right++){
        //     sum += nums[right]; // expand window
            
        //     while(sum >= target){
        //         minLen = min(minLen, (right - left + 1));
        //         sum -= nums[left]; // shrink window
        //         left++;
        //     }
        // }

        // return (minLen == INT_MAX) ? 0 : minLen;

        // method 2:

        int count = INT_MAX, start =0, end =0, sum =0, n = nums.size();

        while(end<n){
            sum += nums[end]; // add the number to the sum

            // we can decrease the length of window
            while(sum>=target){
                count = min(count, (end - start + 1));
                sum -= nums[start];
                start++;
            }
            // if the window cant be decreased furthur then increase the length of window
            end++;
        }
        return (count == INT_MAX) ? 0 : count;
    }
};