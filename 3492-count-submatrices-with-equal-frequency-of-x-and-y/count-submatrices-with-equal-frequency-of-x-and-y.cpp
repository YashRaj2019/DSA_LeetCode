class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));
        vector<vector<int>> countX(n, vector<int>(m, 0));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                prefix[i][j] = val;
                countX[i][j] = (grid[i][j] == 'X');

                if(i > 0) {
                    prefix[i][j] += prefix[i-1][j];
                    countX[i][j] += countX[i-1][j];
                }
                if(j > 0) {
                    prefix[i][j] += prefix[i][j-1];
                    countX[i][j] += countX[i][j-1];
                }
                if(i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i-1][j-1];
                    countX[i][j] -= countX[i-1][j-1];
                }

                // Check conditions
                if(prefix[i][j] == 0 && countX[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};