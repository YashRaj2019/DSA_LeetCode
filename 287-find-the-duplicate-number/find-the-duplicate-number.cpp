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

        int slow = 0;
        int fast = 0;

        do{
            // find intersection point
            slow = nums[slow]; // +1
            fast = nums[nums[fast]]; // +2
        } while (slow != fast);

        // find cycle entrance

        slow = 0;

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};