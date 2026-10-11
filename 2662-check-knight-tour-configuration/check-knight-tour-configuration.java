class Solution {

    boolean isValid(int r, int c, int n, int grid[][], int expVal){

        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal){
            return false;
        }

        if(expVal == n*n -1){
            return true;
        }

        boolean ans1 = isValid(r+2, c+1, n, grid, expVal+1); // right down
        boolean ans2 = isValid(r+2, c-1, n, grid, expVal+1); // right up
        boolean ans3 = isValid(r-2, c+1, n, grid, expVal+1); // left down
        boolean ans4 = isValid(r-2, c-1, n, grid, expVal+1); // left up
        boolean ans5 = isValid(r+1, c-2, n, grid, expVal+1); // up right
        boolean ans6 = isValid(r-1, c-2, n, grid, expVal+1); // up left
        boolean ans7 = isValid(r+1, c+2, n, grid, expVal+1); // down right
        boolean ans8 = isValid(r-1, c+2, n, grid, expVal+1); // down left

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    public boolean checkValidGrid(int[][] grid) {
        return isValid(0, 0, grid.length, grid, 0);
    }
}