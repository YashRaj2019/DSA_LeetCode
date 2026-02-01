class Solution {
public:
    int minimumCost(vector<int>& nums) {

        // Brute force

        // int n = nums.size();
        // int ans = INT_MAX;

        // for(int i=1;i<n;i++){
        //     for(int j=i+1; j<n;j++){
        //         ans=min(ans, nums[i] + nums[j]);
        //     }
        // }

        // return nums[0] + ans;

        // optimal code

        int firstMin = INT_MAX, secondMin = INT_MAX;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<firstMin){
                secondMin = firstMin;
                firstMin = nums[i];
            }

            else if(nums[i]<secondMin){
                secondMin = nums[i];
            }
        }

        return nums[0] + firstMin + secondMin;
    }
};