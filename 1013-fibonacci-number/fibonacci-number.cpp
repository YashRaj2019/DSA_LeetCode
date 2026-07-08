class Solution {
public:

    int fibonc(int n, vector<int> &dp){
        if(n<=1){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = fibonc(n-1, dp) + fibonc(n-2, dp);
    }

    int fib(int n) {
       // method 3 : Using dp

       vector<int>dp(n+1, -1);
       return fibonc(n, dp);

    }
};