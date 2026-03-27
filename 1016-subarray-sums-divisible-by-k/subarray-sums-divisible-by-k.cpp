class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // method 1: Brute force, gives tle
        // int count = 0;
        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         sum += nums[j];

        //         if(sum % k == 0){
        //             count++;
        //         }
        //     }

        // }

        // return count;

        unordered_map<int, int>mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for( int i=0;i<nums.size();i++){
            sum += nums[i];

        // method 1

        //     int rem = sum % k;

        //     if(rem < 0){
        //         rem = rem + k;
        //     }

        //     if(mp.count(rem)){
        //         count += mp[rem];
        //         mp[rem]++;
        //     }
        //     else{
        //         mp[rem] = 1;
        //     }

        
            //method 2
            int rem =((sum % k)  + k) % k; // handle negative
            count += mp[rem];
            mp[rem]++;
        }

        return count;
        
    }
};