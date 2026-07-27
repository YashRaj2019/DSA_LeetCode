class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return (nums[n-1]-1) * (nums[n-2]-1);

        // method 2: optimal solution
        int first = 0, second = 0;

        for(auto num : nums){
            if(num > first){
                second = first;
                first = num;
            }
            else if(num > second){
                second = num;
            }
        }

        return (first - 1) * (second - 1);

    }
};