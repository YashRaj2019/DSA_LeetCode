class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
    
        // Step 1: find global max
        int maxi = *max_element(nums.begin(), nums.end());
        
        long long ans = 0;
        int left = 0, countMax = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == maxi) countMax++;

            // shrink until invalid
            while (countMax >= k) {
                ans += (n - right);

                if (nums[left] == maxi) countMax--;
                left++;
            }
        }

        return ans; 
    }
};