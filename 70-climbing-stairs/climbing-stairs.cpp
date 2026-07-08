class Solution {
public:
    int climbStairs(int n) {

       if(n<=3){
            return n;
       }

       vector<int>dp(3);
       dp[0] = 1;
       dp[1] = 2;
       dp[2] = 3;

       for(int i=4; i<=n; i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[0] + dp[1];
       }
        return dp[2];
    }
}; 