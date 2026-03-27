class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        // // method 1
        // unordered_map<int, int>mp;
        // int left = 0, maxLen = 0;

        // for(int right=0;right<nums.size();right++){
        //     mp[nums[right]]++;
        //     // if current element exceeds k, shrink window
        //     while(mp[nums[right]] > k){
        //         mp[nums[left]]--;
        //         left++;
        //     }
        //     maxLen = max(maxLen, (right - left + 1));
        // }
        // return maxLen;

        // method 2 : 
        unordered_map<int, int>count;
        int len = 0;
        int start = 0, end = 0, n = nums.size();

        while(end < n){
            count[nums[end]]++;

            while(count[nums[end]] > k){
                count[nums[start]]--;
                start++;
            }

            len = max(len, (end - start + 1));
            end++;
        }
        return len;
    } 
};