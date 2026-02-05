class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
                continue;
            }

            int pos = i;
            int steps = abs(nums[i]);

            while (steps--) {
                if (nums[i] > 0) {      // move right
                    pos++;
                    if (pos == n) pos = 0;
                } else {               // move left
                    pos--;
                    if (pos < 0) pos = n - 1;
                }
            }

            result[i] = nums[pos];
        }

        return result;
    }
};
