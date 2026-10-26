class Solution {
    public int countIslands(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    if (dfs(grid, vis, i, j, k) % k == 0)
                        count++;
                }
            }
        }
        return count;
    }

    long dfs(int[][] g, boolean[][] vis, int i, int j, int k) {
        if (i < 0 || j < 0 || i >= g.length ||
            j >= g[0].length || g[i][j] == 0 || vis[i][j])
            return 0;

        vis[i][j] = true;

        return g[i][j]
            + dfs(g, vis, i + 1, j, k)
            + dfs(g, vis, i - 1, j, k)
            + dfs(g, vis, i, j + 1, k)
            + dfs(g, vis, i, j - 1, k);
    }
}