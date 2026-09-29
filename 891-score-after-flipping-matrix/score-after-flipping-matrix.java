class Solution {
    public int matrixScore(int[][] grid) {
        // 0th col of the matrix should have all ones
        int m = grid.length, n = grid[0].length;
        for(int i=0; i<m; i++){
            if(grid[i][0]==0){ // flip that row
                for(int j=0; j<n; j++){
                    grid[i][j] ^= 1;
                    // grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        // flip the column which has no of 0's > no of 1's
        for(int j=0; j<n; j++){
            int zeros = 0, ones = 0;
            for(int i=0; i<m; i++){
                if(grid[i][j] == 0){
                    zeros++;
                }
                else{
                    ones++;
                }
            }

            if(zeros > ones){ //flip that rows
                for(int i=0; i<m; i++){
                    grid[i][j] ^= 1;
                }

            }
        }

        int sum = 0;
        int pow = 1;

        for(int j = n-1; j >=0; j--){
            int ones = 0;
            for(int i=0; i<m; i++){
                if(grid[i][j] == 1){
                    ones++;
                }
            }
            sum += pow * ones;
            pow *= 2;
        }
        return sum;
    }
}