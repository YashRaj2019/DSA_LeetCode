class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // step1 : brute force
        int total =0;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j]; // accumulate proprty

                if(sum==k){
                    total++;
                } 
            }
        }
        return total;
    }
};