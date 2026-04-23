class Solution {
public:

    int fibon(int n, vector<int> &dp){

    
        // base case
        if(n <= 1){
            return n;
        }
            // need not to calculate already calculated result
            if(dp[n] != -1){
                return dp[n];
            }
            return dp[n] = fibon(n-1, dp) + fibon(n-2, dp);
    }

    int fib(int n) {

        // method 1 : using loop

        // if(n<=1){   // base case
        //     return n;
        // }

        // int prev2 = 0; // f(0)
        // int prev1 = 1; // (f1)

        // for(int i=2;i<=n;i++){
        //     int curr = prev1 +prev2;
        //     prev2 = prev1;
        //     prev1 =curr;
        // }

        // return prev1;

        // // method 2 : using recursion
        // if(n==0 || n==1){  // base case
        //     return n;
        // }

        // return fib(n-1) + fib(n-2);


        // method 3: optimised using dp

        vector<int> dp(n+1, -1);
        return fibon(n, dp);
        
    }
};