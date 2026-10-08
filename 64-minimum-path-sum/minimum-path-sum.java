class Solution {

    public int helper(int[][] grid,int[][] dp, int m, int n){

        if(m == 0 && n == 0){
            return grid[0][0];
        }

        if (m < 0 || n < 0) {
            return Integer.MAX_VALUE;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int up = helper(grid, dp, m-1, n);
        int left = helper(grid, dp, m, n-1);

        return dp[m][n] = grid[m][n] + Math.min(up, left);
    }

    public int minPathSum(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m][n];
        for(int i = 0; i<m; i++){
            Arrays.fill(dp[i], -1);
        }
        
        return helper(grid, dp, m-1, n-1);
    }
}