class Solution {
public:

    void helper(int i, vector<int>& nums, vector<int>& ans, vector<vector<int>> &getAllSubsets){
        if(i == nums.size()){
            getAllSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        helper(i+1, nums, ans, getAllSubsets);

        ans.pop_back(); // backtrack

        int index = i+1;
        while(index < nums.size() && nums[index] == nums[index-1]){
            index++;
        }

        // exclude
        helper(index, nums, ans, getAllSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<int>ans;
       vector<vector<int>>getAllSubsets;
       helper(0, nums, ans, getAllSubsets);
       return getAllSubsets; 
    }
};