class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        //  for(int i = 1; i < stones.size(); i++)
        //     stones[i] += stones[i - 1];

        // int ans = stones.back();

        // for(int i = stones.size() - 2; i >= 1; i--)
        //     ans = max(ans, stones[i] - ans);

        // return ans;

         int n = stones.size();
        
        // prefix sum
        vector<int> prefix(n);
        prefix[0] = stones[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        
        // dp[i] = maximum score difference Alice can achieve
        // starting from prefix[i]
        int dp = prefix[n - 1];
        
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }
        
        return dp;
    }
};