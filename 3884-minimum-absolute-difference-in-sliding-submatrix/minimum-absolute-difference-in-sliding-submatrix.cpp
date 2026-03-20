class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> s;

                for (int x = i; x < i + k; x++)
                    for (int y = j; y < j + k; y++)
                        s.insert(grid[x][y]);

                if (s.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                int prev = *s.begin(), mini = INT_MAX;

                for (auto it = next(s.begin()); it != s.end(); it++) {
                    mini = min(mini, *it - prev);
                    prev = *it;
                }

                ans[i][j] = mini;
            }
        }

        return ans;
    }
};