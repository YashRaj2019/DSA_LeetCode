class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int>mp;

        // count frequency
        for(auto it : nums){
            mp[it]++;
        }

        // find maximum frequency
        int maxFreq = 0;
        for(auto it : mp){
            maxFreq = max(maxFreq, it.second);
        }

        // sum frequencies of elements having maximum frequency
        int ans = 0;
        for(auto it : mp){
            if(it.second == maxFreq){
                ans += it.second;
            }
        }
        return ans;

    }
};