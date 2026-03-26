class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // step1 : brute force, time complexity : n^2
        // int total =0;
        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         sum += nums[j]; // accumulate proprty

        //         if(sum==k){
        //             total++;
        //         } 
        //     }
        // }
        // return total;

        //method 2: use concept of prefixsum, optimal, time complexity = n

        int total =0, sum =0;
        unordered_map<int, int>mp;
        mp[0] = 1;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            // method 1: 

            // if(mp.find(sum - k) != mp.end()){
            //     total += mp[sum - k];
            // }
            // mp[sum]++;

            // mrthod 2: 

            if(mp.count(sum - k)){
                total += mp[sum - k];
                mp[sum]++;
            }
            else{
                mp[sum]++;
            }
        }

        return total;
    }
};