class Solution {

    public int helper(int i, int j, String s1, String s2, int[][] dp){

        if(i==s1.length()){
            return s2.length()-j;
        }

        if(j==s2.length()){
            return s1.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1.charAt(i) == s2.charAt(j)){
            return helper(i+1, j+1, s1, s2, dp);
        }

        int insert = 1 + helper(i, j+1, s1, s2, dp);
        int delete = 1 +  helper(i+1, j, s1, s2, dp);
        int replace = 1 +  helper(i+1, j+1, s1, s2, dp);

        return dp[i][j] =  Math.min(insert, Math.min(delete, replace));
    }

    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length()][word2.length()];
        for(int i=0; i<dp.length; i++){
            Arrays.fill(dp[i], -1);
        }
        return helper(0, 0, word1, word2, dp);
    }
}


// class Solution {

//     public int helper(int i, int j, String s1, String s2){

//         if(i==s1.length()){
//             return s2.length()-j;
//         }

//         if(j==s2.length()){
//             return s1.length()-i;
//         }

//         if(s1.charAt(i) == s2.charAt(j)){
//             return helper(i+1, j+1, s1, s2);
//         }

//         int insert = 1 + helper(i, j+1, s1, s2);
//         int delete = 1 +  helper(i+1, j, s1, s2);
//         int replace = 1 +  helper(i+1, j+1, s1, s2);

//         return Math.min(insert, Math.min(delete, replace));
//     }

//     public int minDistance(String word1, String word2) {
//         return helper(0, 0, word1, word2);
//     }
// }