class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // for(int i=0; i<n; i++){
        //     nums1[m+i] = nums2[i];
        // }

        // sort(nums1.begin(), nums1.end());

        nums1.resize(m);
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

    }
};