class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        // vector<int>freq(1001, 0);
        // vector<int>ans;

        // for(int i=0; i<nums1.size(); i++){
        //     freq[nums1[i]]++;
        // }

        // for(int i=0; i<nums2.size(); i++){
        //     if(freq[nums2[i]] > 0){
        //         ans.push_back(nums2[i]);
        //         freq[nums2[i]]--;
        //     }
        // }
        // return ans;


        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {
                    ans.push_back(nums1[i]);

                    nums2[j] = -1;  // mark this occurrence as used

                    break;
                }
            }
        }
        return ans;
    }
};