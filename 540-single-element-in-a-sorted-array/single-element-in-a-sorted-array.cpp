class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // int ans=0;
        // for(int i=0; i<nums.size(); i++){
        //     ans ^= nums[i];
        // }
        // return ans;

        // method 2: using umordered map
        unordered_map<int, int>mp;
        int ans = 0;
        for(auto it: nums){
            mp[it]++;
        }
        
        for(auto it: mp){
            if(it.second == 1){
                return it.first;
            }
        }

        return -1;

    }
};