class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int  N = n * n;

        vector<int>ans(N+1, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[grid[i][j]]++;
            }
        }

        int repeated = -1;
        int missing = -1;

        for(int i=1; i<=N; i++){
            if(ans[i] == 2){
                repeated = i;
            }

            if(ans[i] == 0){
                missing = i;
            }
        }
        return {repeated, missing};

    }
};