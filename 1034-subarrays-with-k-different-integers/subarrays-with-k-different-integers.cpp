class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0, distinct = 0, count = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(freq[nums[right]] == 0) distinct++;
            freq[nums[right]]++;

            while(distinct > k) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) distinct--;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};