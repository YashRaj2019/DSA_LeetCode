class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        // step 1: sort the array by starting time
        sort(intervals.begin(), intervals.end());

        // step 2: Add the first interval
        ans.push_back(intervals[0]);

        // step 3 : traverse the remaining array
        for(int i=1; i<intervals.size(); i++){

            // if current interval overlaps with the last interval in ans
            if(intervals[i][0] <= ans.back()[1]){

                // merge by updating the end time
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }

            else{
                // no overlap, add the current element
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};