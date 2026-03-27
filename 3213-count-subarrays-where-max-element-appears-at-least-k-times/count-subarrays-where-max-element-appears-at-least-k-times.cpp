class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    //    int n = nums.size();
    
        // // method 1:
        // // Step 1: find global max
        // int maxi = *max_element(nums.begin(), nums.end());
        
        // long long ans = 0;
        // int left = 0, countMax = 0;

        // for (int right = 0; right < n; right++) {
        //     if (nums[right] == maxi) countMax++;

        //     // shrink until invalid
        //     while (countMax >= k) {
        //         ans += (n - right);

        //         if (nums[left] == maxi) countMax--;
        //         left++;
        //     }
        // }

        // return ans; 


        // method: 2

        int maxEle = 0, n = nums.size();
        for(int i=0;i<n;i++){
            maxEle = max(maxEle, nums[i]);
        }

        long long total = 0;
        int count = 0, start = 0, end = 0;

        while(end < n){
            if(nums[end]==maxEle){
                count++;
            }

            while(count==k){
                total += n-end;
                if(nums[start]==maxEle){
                    count--;
                }
                start++;
            }
            end++;
        }

        return total;
    }
};