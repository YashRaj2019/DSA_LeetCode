class Solution {
public:

    void permutation(int index, vector<int>& nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]); // for index place we take the ith element choice
            permutation(index+1, nums, ans);

            swap(nums[index], nums[i]); // backtracking

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation(0, nums, ans);
        return ans;
    }
};