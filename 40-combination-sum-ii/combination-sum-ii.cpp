class Solution {
public:

    void findComb(int index, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>&ans){

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i= index; i < candidates.size(); i++){
            // skip the duplicates at the same recursion level
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            // no need to continue furthur ( array is sorted )
            if(candidates[i] > target){
                break;
            }

            temp.push_back(candidates[i]);

            // move to next index (cannot use the same element)
            findComb(i + 1, target - candidates[i], candidates, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        findComb(0, target, candidates, temp, ans);
        return ans;

    }
};