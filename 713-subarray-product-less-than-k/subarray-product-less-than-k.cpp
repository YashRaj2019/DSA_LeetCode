class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // method 1: Brute force
        // int count = 0;
        // for(int i=0; i<nums.size();i++){
        //     int product = 1;
        //     for(int j=i; j<nums.size();j++){
        //         product *= nums[j];

        //         if(product < k){
        //             count++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return count;



        // method 2:
        // int product = 1, start = 0, end = 0, n = nums.size(), count = 0;

        // while(end<n){
        //     product *= nums[end];

        //     while(product >= k && start<= end){
        //         product /= nums[start];
        //         start++;
        //     }

        //     count += 1 + (end - start);
        //     end++;
        // }

        // return count;


        // method 3: 
        if(k<=1){
            return 0;
        }

        int left = 0;
        long long product = 1;
        int count = 0;

        for(int right = 0; right < nums.size(); right++){
            product *= nums[right];

            while(product >= k){
                product /= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;

    }
};