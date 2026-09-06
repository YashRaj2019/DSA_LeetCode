// class Solution {
// public:

//     int solve(string &s, string &t, int i, int j){
//         // t is completely matched
//         if(j == t.size()){
//             return 1;
//         }

//         // s is finished but t is still left
//         if(i == s.size()){
//             return 0;
//         }

//         int ans = 0;

//         // if character match, we have two choice
//         if(s[i] == t[j]){
//             ans += solve(s, t, i + 1, j + 1); // take it
//             ans += solve(s, t, i + 1 ,j); // don't take it
//         }
//         else{
//             // can't take s[i]
//             ans += solve(s, t, i + 1, j);
//         }

//         return ans;

//     }

//     int numDistinct(string s, string t) {
//         return solve(s, t, 0, 0);
//     }
// };


class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp(n + 1,
            vector<unsigned long long>(m + 1, 0));

        // Empty t can always be formed in 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Don't take s[i-1]
                dp[i][j] = dp[i-1][j];

                // Take s[i-1] if characters match
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }

        return dp[n][m];
    }
};