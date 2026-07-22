class Solution {
public:

    void printSubsets(vector<int>& nums, vector<int>& ans, vector<vector<int>> &allSubsets, int i, int n){
        if(i == n){
            allSubsets.push_back(ans);   // Store the current subset
            return;
        }
        
        ans.push_back(nums[i]);
        printSubsets(nums, ans, allSubsets, i+1, n);

        ans.pop_back();
        printSubsets(nums, ans, allSubsets, i+1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        int n = nums.size();
        vector<int>ans;
        printSubsets(nums, ans, allSubsets, 0, n);
        return allSubsets;
    }
};