class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newCol;

                if(i % 2 == 0){
                    newCol = (j + k) % n; // left shift
                }
                else{
                    newCol = (j - k + n) % n; // right shift
                }
                if(mat[i][j] != mat[i][newCol]){
                    return false;
                }
            }
        }
        return true;
    }
};