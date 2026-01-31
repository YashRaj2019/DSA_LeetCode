class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

    //     // Next smallest left
    //     // Next smallest left

    //     int n = heights.size();
    //     vector<int>Right(n);
    //     vector<int>Left(n);
    //     stack<int>st;

    //     // Find next smaller in right

    //     for(int i=0;i<n;i++){
    //         while(!st.empty() && heights[st.top()] > heights[i]){
    //             Right[st.top()] = i;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }

    //     // empty the stack because we need fo find next smallest right for everyone

    //     while(!st.empty()){
    //         Right[st.top()] = n;
    //         st.pop();
    //     }

    //     // next smallest left

    //     for(int i=n-1;i>=0;i--){
    //         while(!st.empty() && heights[st.top()] > heights[i]){
    //             Left[st.top()] = i;
    //             st.pop();
    //         }

    //         st.push(i);
    //     }

    //     // empty the stack because we need fo find next smallest right for everyone

    //     while(!st.empty()){
    //         Left[st.top()] = -1;
    //         st.pop();
    //     }
    

    // // calculate the area

    //     int ans = 0;

    //     for(int i=0;i<n;i++){
    //         ans = max(ans, heights[i]*(Right[i] - Left[i] - 1));
    //     }

    //     return ans;

        // Method 2

        int ans  = 0;
        int index;

        stack<int>st;
        int n = heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                index = st.top();
                st.pop();

                if(!st.empty()){
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                }

                else{
                    ans = max(ans, heights[index] * i);
                }
            }
            st.push(i);
        }

        while(!st.empty()){
            index = st.top();
            st.pop();

            if(!st.empty()){
                ans = max(ans, heights[index] * (n - st.top() - 1));
            }

            else{
                ans = max(ans, heights[index] * n);
                }
          
        }
        return ans;
    }
};