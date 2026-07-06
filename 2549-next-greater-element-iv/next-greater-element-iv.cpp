class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st1;
        stack<int>st2;

        vector<int>temp;

        // found the second greater element
        for(int i=0; i<n; i++){
            while(!st2.empty() && nums[i] > nums[st2.top()]){
                ans[st2.top()] = nums[i];
                st2.pop();
            }

            // Move elemet that found first greater
            temp.clear();

            while(!st1.empty() && nums[i] > nums[st1.top()]){
                temp.push_back(st1.top());
                st1.pop();
            }

            // maintain order while moving
            for(int j=temp.size() -1; j >= 0; j--){
                st2.push(temp[j]);
            }

            st1.push(i);
        }
        return ans;
    }
};