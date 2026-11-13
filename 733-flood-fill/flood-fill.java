class Solution {

    void dfs(int[][] image, int i, int j, int newCol, int oldCol){
        if(i<0 || j<0 || i>=image.length || j>=image[0].length || image[i][j] != oldCol || image[i][j] == newCol){
            return;
        }

        image[i][j] = newCol;

        dfs(image, i-1, j, newCol, oldCol);
        dfs(image, i, j+1, newCol, oldCol);
        dfs(image, i+1, j, newCol, oldCol);
        dfs(image, i, j-1, newCol, oldCol);
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
}