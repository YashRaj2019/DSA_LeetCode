class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       // method 1: brute force : o(n^2) 

        // vector<int>ans;
        // for(int i=0;i<nums.size(); i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};

        //         }
        //     }
        // }
        // return {};

        // method 2 : using two pointer approach

        vector<pair<int, int>>ans;

        for(int i=0; i<nums.size(); i++){
            ans.push_back({nums[i], i});
        }

        sort(ans.begin(), ans.end());

        int start = 0, end = ans.size()-1;

        while(start < end){
            int sum = ans[start].first + ans[end].first;

            if(sum == target){
                return {ans[start].second, ans[end].second};
            }
            else if(sum < target){
                start++;
            }

            else{
                end--;
            }
        }
        return {};
    }
};