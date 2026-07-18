class Solution {
public:
    int findGCD(vector<int>& nums) {

        // sort(nums.begin(), nums.end()); // method 1: 

        // int a = nums[0];
        // int n = nums.size();
        // int b = nums[n-1];

        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());

        while(a > 0 and b > 0){
            if(a > b){
                a = a % b;
            }
            else{
                b = b % a;
            }
        }

        if(a ==0 ){
            return b;
        }

        return a;


    }
};