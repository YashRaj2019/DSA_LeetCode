class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n, -1); // smaller left element
        vector<int>right(n, -1); // smaller right element
        stack<int>st;

         // samller right elemet
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i]<= heights[st.top()]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // smaller left element
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int area = 0;
        for(int i=0; i<n; i++){

            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;

            area = max(area, currArea);

        }
        return area;

    }
};