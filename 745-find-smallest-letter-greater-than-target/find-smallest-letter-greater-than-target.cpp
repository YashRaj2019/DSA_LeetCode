class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // for(int i=0;i<letters.size();i++){
        //     if(letters[i] >target){
        //         return letters[i];
        //     }
        // }
        // return letters[0];


        int n = letters.size();
        int l = 0, r = n - 1;
        char ans = letters[0];   // default wrap-around answer

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];
                r = mid - 1;   // try to find smaller valid char
            } else {
                l = mid + 1;
            }
        }

        return ans;

        

    }
};