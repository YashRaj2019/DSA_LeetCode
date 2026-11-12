class Solution {
    class Pair{
        int row;
        int col;
        Pair(int row, int col){
            this.row = row;
            this.col = col;
        }
    }
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<Pair> q = new LinkedList<>();
        int fresh = 0, time = 0;

        // Add all rotten oranges initially
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.add(new Pair(i, j));
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        while(!q.isEmpty() && fresh > 0){
            int size = q.size();
            time++;

            for(int i=0; i<size; i++){
                Pair curr = q.poll();

                for(int d=0; d<4; d++){
                    int x = curr.row + dx[d];
                    int y = curr.col + dy[d];

                    if(x >=0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] =  2;
                        fresh--;
                        q.add(new Pair(x, y));
                    }
                }
            }
        } 
        return fresh == 0 ? time : -1;
    }
}