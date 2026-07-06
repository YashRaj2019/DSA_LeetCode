class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        //find the pivot
        int i = s.size() - 2;

        while(i >= 0 && s[i] >= s[i+1]){
            i--;
        }

        if(i == -1){
            return -1;
        }

        // find the next greater digit
        int j = s.size() - 1;
        while(s[j] <= s[i]){
            j--;
        }

        swap(s[i], s[j]);

        // make the remaining part smallest
        reverse(s.begin() + i + 1, s.end());

        long long num = stoll(s);

        return (num > INT_MAX) ? -1 : num;

    }
};