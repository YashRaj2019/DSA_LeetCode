class Solution {
public:

    void solve(vector<char> &s, int left, int right){
        // base case
        if(left >= right){
            return;
        }

        // swap first and last
        swap(s[left], s[right]);

        // Move towards the middle
        solve(s, left+1, right-1);
    }

    void reverseString(vector<char>& s) {
        solve(s, 0, s.size()-1);
    }
};