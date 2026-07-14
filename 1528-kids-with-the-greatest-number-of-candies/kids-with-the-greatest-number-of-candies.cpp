class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans;

        int maxi = *max_element(candies.begin(), candies.end());
        int sum =0;
        for(int i=0; i<n; i++){
            sum = candies[i] + extraCandies;
            if(sum >= maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};