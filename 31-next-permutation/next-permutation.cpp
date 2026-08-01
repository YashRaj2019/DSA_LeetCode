class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // step1 : Find the pivot
        int pivot = -1;

        for(int i=n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        // step 2 : if no pivot exist, reverse the entire array
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // step 3: Find the smallest greater element
        for(int i=n-1; i>pivot; i--){
            if(nums[i] >nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // step 4 : Reverse the suffix
        reverse(nums.begin() + pivot+1, nums.end());
    }
};