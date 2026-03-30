class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // method 1 : (Time, space : n, 1)
        // int count = 0;
        // int candidate = 0;

        // for(int i=0;i<nums.size();i++){
        //     if(count == 0){
        //         candidate = nums[i];
        //     }

        //     if(nums[i]==candidate){
        //         count++;
        //     }
        //     else{
        //         count--;
        //     }
        // }

        // return candidate;


        // method 2: Brute force, tle , (Time, space : n^2, 1)

        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     int count = 0;

        //     for(int j = 0; j < n; j++){
        //         if(nums[j] == nums[i])
        //             count++;
        //     }

        //     if(count > n/2)
        //         return nums[i];
        // }

        // return -1; // never reached (majority guaranteed)

        // method 3: hashing, (Time, space : n, n)

        // unordered_map<int,int> mp;
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     mp[nums[i]]++;

        //     if(mp[nums[i]] > n/2)
        //         return nums[i];
        // }

        // return -1;

        // method 4: sorting: (Time, space : nlogn, 1(if in-place sort))
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};