// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // brute force

//         // int n=nums.size();
//         // vector<int>ans;

//         // for(int i=0;i<=n-k;i++){
//         //     int total = INT_MIN;
//         //     for(int j=i; j<i+k; j++){
//         //         total = max(total, nums[j]);
//         //     }
//         // ans.push_back(total);
//         // }

//         // return ans;

//         // optimal method: solved using deque

//         int n = nums.size();
//         deque<int>dq;
//         vector<int>ans;

//         for(int i=0;i<k-1;i++){
//             if(dq.empty()){
//                 dq.push_back(i);
//             }

//             else{
//                 while(!dq.empty() && nums[i]>nums[dq.back()]){
//                     dq.pop_back();
//                 }

//                 dq.push_back(i);
//             }
//         }

//         for(int i=k-1;i<n;i++){
//             // Remove smaller element
//             while(!dq.empty() && nums[i]>nums[dq.back()]){
//                 dq.pop_back();
//             }

//             dq.push_back(i);

//             // if the front element is outside the window, pop it

//             if(dq.front()<=i-k){
//                 dq.pop_front();
//             }

//             ans.push_back(nums[dq.front()]);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>dq;
       vector<int>res;

       // 1st window
       for(int i=0; i<k; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
       }

       for(int i=k; i<nums.size(); i++){
            res.push_back(nums[dq.front()]);

            // remove not part of current window
            while(dq.size() > 0 && dq.front() <= i-k){
                dq.pop_front();
            }

            // remove the smaller value from end
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
       }

        res.push_back(nums[dq.front()]);
        return res;
    }
};