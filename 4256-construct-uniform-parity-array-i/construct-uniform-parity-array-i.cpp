class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // return true;

        int n = nums1.size();

        // find and odd number
        int odd = -1;

        for(int i=0; i<n; i++){
            if(nums1[i] % 2 != 0){
                odd = nums1[i];
                break;
            }
        }

        // If no odd number exist, all numbers are already even
        if(odd == -1){
            return -1;
        }

        // const nums2
        vector<int>nums2;

        for(int i=0; i<n; i++){
            if(nums1[i]%2 != 0){
                // alreday odd, keep it
                nums2.push_back(nums1[i]);
            }
            else{
                // even - odd = odd
                nums2.push_back(nums1[i] - odd);
            }
        }

        // check for all elements are odd
        for(auto it : nums2){
            if(it % 2 == 0){
                return false;
            }
        }

        return true;
    }
};