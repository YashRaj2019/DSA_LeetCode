class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        while (srow <= erow && scol <= ecol) {

            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }
            srow++;

            // right
            for (int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;

            // bottom
            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--) {
                    ans.push_back(matrix[erow][j]);
                }
                erow--;
            }

            // left
            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
                scol++;
            }
        }

        return ans;
    }
};