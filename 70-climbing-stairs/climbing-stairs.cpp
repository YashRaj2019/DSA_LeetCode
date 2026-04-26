// class Solution {
// public:

//     int count(int i, int n){
//         if(i==n){
//             return 1;
//         }

//         if(i>n){
//             return 0;
//         }

//         return count(i+1, n) + count(i+2, n);
//     }

//     int climbStairs(int n) {
         
//         // method 1 : using iterative approach 

//         // if(n<=2){
//         //     return n;
//         // }

//         // int prev2 = 1; // ways to reach one step
//         // int prev1 = 2; // ways to reach two step

//         // for(int i=3; i<=n; i++){
//         //     int curr = prev1 + prev2;
//         //     prev2 = prev1;
//         //     prev1 = curr;
//         // }

//         // return prev1;


//         // method 2 : using recursion, tle

//         return count(0, n);

//     }
// };

class Solution {
public:

    // method 3 : using dp

    int count(int i, int n, vector<int> &dp){
        if(i==n){
            return 1;
        }

        if(i>n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = count(i+1, n, dp) + count(i+2, n, dp);
    }

    int climbStairs(int n) {
         
        vector<int> dp(n+2, -1);
        return count(0, n, dp);

    }
};