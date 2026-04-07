class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>freq;

        for(auto i : nums){
            freq[i]++;
        } 

        // find element with frequency 1

        for(auto it : freq){
            if(it.second == 1){
                return it.first;
            }
        }

        return -1; // fallback should never happen
    }
};