class Solution {
public:

    set<vector<int>> s;
    
    void getAllCombinations(vector<int>& arr,int idx, int target, vector<vector<int>> &ans, vector<int> &combination){

        if(idx == arr.size() || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back(combination);
                s.insert(combination);
            }
            return;
        }

        combination.push_back(arr[idx]);

        getAllCombinations(arr, idx+1, target - arr[idx], ans, combination); // single

        getAllCombinations(arr, idx, target - arr[idx], ans, combination); // multiple

        combination.pop_back();    // backtracing

        getAllCombinations(arr, idx+1, target, ans, combination); // exclusion
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combination;

        getAllCombinations(arr, 0, target, ans, combination); 

        return ans;

    }
};