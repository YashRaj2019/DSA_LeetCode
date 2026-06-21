class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

    //    int n = nums.size();
    //    vector<int>ans(n, -1);
    //    stack<int>st;

    //   for(int i=0;i<2*n;i++){
    //      int idx = i%n;
    //     while(!st.empty() && nums[st.top()] < nums[idx]){
    //         ans[st.top()] = nums[idx];
    //         st.pop();
    //     }

    //     if(i<n){
    //         st.push(idx);
    //     }
    //   } 
    //   return ans;

    // method 2: 

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for(int i=2*n-1; i>=0; i--){
            while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};