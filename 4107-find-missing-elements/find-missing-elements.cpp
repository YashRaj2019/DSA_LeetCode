class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // // method 1 : Brute force
        // sort(nums.begin(), nums.end());

        // vector<int>ans;

        // for(int i=0; i<nums.size()-1; i++){
        //     for(int x = nums[i]+1; x < nums[i+1]; x++){
        //         ans.push_back(x);
        //     }
        // }
        // return ans;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        unordered_set<int>st(nums.begin(), nums.end());

        vector<int>ans;

        for(int i = mini + 1; i < maxi; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};