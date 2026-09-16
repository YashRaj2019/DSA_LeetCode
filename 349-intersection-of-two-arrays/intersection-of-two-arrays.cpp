class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool>res(1001, false);
        vector<int>ans;

        for(int i=0; i<nums1.size(); i++){
            res[nums1[i]] = true;
        }

        for(int i=0; i<nums2.size(); i++){
            if(res[nums2[i]]){
                ans.push_back(nums2[i]);
                res[nums2[i]] = false;
            }
        }

        return ans;
    }
};