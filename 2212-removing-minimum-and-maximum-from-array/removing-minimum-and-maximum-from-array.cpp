class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int l = min(mini, maxi);
        int r = max(mini, maxi);

        return min({
            r + 1,           // remove both from left
            n - l,            // remove both from right
            l + 1 + n - r     // remove one from each side
        });
    }
};