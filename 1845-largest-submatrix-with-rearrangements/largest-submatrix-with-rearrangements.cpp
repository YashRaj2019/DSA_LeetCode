class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // step 1 : build height

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        int maxArea = 0;

        // step 2: +3
        for(int i=0;i<m;i++){
            vector<int>arr = matrix[i];
            sort(arr.begin(), arr.end(), greater<int>()); // descending

            for(int j=0; j<n; j++){
                int area = arr[j] * (j + 1);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;

    }
};