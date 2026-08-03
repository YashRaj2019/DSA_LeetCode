class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        // // Method: 1
        // vector<int>ans;
        // for(auto it : nums){
        //     if(it < pivot){
        //         ans.push_back(it);
        //     }
        // }
        // for(auto it : nums){
        //     if(it == pivot){
        //         ans.push_back(it);
        //     }
        // }
        // for(auto it : nums){
        //     if(it > pivot){
        //         ans.push_back(it);
        //     }
        // }
        // return ans;

        // Method 2 : 

        vector<int>less, equal, greater;

        for(auto it : nums){

            if(it < pivot){
                less.push_back(it);
            }

            else if(it == pivot){
                equal.push_back(it);
            }

            else{
                greater.push_back(it);
            }
        }

        vector<int>ans;
        ans.insert(ans.end(), less.begin(), less.end());
        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), greater.begin(), greater.end());

        return ans;
    }
};