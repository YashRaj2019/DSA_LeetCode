class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // //method 1: Brute force, gives tle
        // int count = 0;
        // for(int i=0;i<nums.size();i++){
        //     long long sum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         sum += nums[j];

        //         long long len  = j - i +1;

        //         if(sum *len < k){
        //             count++;
        //         }
        //     }

        // }

        // return count;

        // method 2: time complexity n

        long long sum = 0, count = 0;
        int left = 0;

        for(int right=0;right<nums.size();right++){
            sum += nums[right];

            while(sum * (right - left + 1) >= k){
                sum -= nums[left];
                left++;
            }

            count += (right -left + 1);
        }

        return count;
    }
};