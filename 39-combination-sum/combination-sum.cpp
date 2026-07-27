class Solution {
public:

    void findCombination(int index, int target, vector<int>& candidates, vector<vector<int>>&ans, vector<int>&temp){
        // base case
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        // pick up the element
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            findCombination(index, target - candidates[index], candidates, ans, temp); // picking multiple element
            temp.pop_back(); // backtrack
        }

        findCombination(index+1, target, candidates, ans, temp); // picking single element

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        findCombination(0, target, candidates, ans, temp);
        return ans;

    }
};