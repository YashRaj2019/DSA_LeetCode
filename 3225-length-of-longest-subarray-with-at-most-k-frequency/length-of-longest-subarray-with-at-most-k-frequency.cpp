class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int left = 0, maxLen = 0;

        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            // if current element exceeds k, shrink window
            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
            maxLen = max(maxLen, (right - left + 1));
        }
        return maxLen;

    } 
};