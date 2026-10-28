class Solution {


    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();

        int[][] dp = new int[m+1][n+1];
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
}
// class Solution {

//     public int lcs(int i, int j, StringBuilder s1, StringBuilder s2, int[][] dp){

//         if(i<0 || j < 0){
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(s1.charAt(i) == s2.charAt(j)){
//             return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, dp);
//         }
//         else{
//             return dp[i][j] = Math.max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
//         }
//     }

//     public int longestCommonSubsequence(String text1, String text2) {
//         int m = text1.length(), n = text2.length();

//         int[][] dp = new int[m][n];
//         for(int i=0; i<m; i++){
//             Arrays.fill(dp[i], -1);
//         }
//         return lcs(m-1, n-1, new StringBuilder(text1), new StringBuilder(text2), dp);
//     }
// }