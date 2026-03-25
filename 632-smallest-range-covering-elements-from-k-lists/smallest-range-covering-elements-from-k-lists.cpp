class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        // {pair: value, row, column},  min heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>p;

        int maxi = INT_MIN;
        //  step 1 :insert first element of each row into heap

        for(int i=0;i<nums.size();i++){
            p.push({nums[i][0], {i,0}});
            maxi = max(maxi, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        // step 2: Process heap

        // Step 2: process heap
        while (true) {
            auto temp = p.top();
            p.pop();
            
            int mini = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
            // Update range
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            
            // Move forward in same list
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                p.push({nextVal, {row, col + 1}});
                
                maxi = max(maxi, nextVal);
            } else {
                break; // one list finished
            }
        }
        
        return {start, end};
        
    }
};