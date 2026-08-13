class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // // method 1 : using hashing : O(n), O(n)

        // unordered_set<int>s;

        // for(int val : nums){
        //     if(s.find(val) != s.end()){
        //         return val;
        //     }

        //     s.insert(val);
        // }

        // return -1;

        // 

        // method 2: using slow and fast pointer, O(n), O(1)

        // int slow = 0;
        // int fast = 0;

        // do{
        //     // find intersection point
        //     slow = nums[slow]; // +1
        //     fast = nums[nums[fast]]; // +2
        // } while (slow != fast);

        // // find cycle entrance

        // slow = 0;

        // while(slow != fast){
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }

        // return slow;
        
        /// brute force: tle
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(nums[i] == nums[j]){
        //             return nums[i];
        //             break;
        //         }
        //     }
        // }
        // return -1;

        unordered_map<int, int>mp;
        for(auto it : nums){
            mp[it]++;
        }

       for(int i=0; i<nums.size(); i++){
          if(mp[nums[i]] > 1){
            return nums[i];
          }
       }
        return -1;
    }
};