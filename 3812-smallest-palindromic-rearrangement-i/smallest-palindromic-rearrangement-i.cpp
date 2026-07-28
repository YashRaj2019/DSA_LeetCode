class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int>freq(26, 0);

        // count frequency of each character
        for(auto ch : s){
            freq[ch - 'a']++;
        }

        string left = "";
        string middle = "";

        // Build left half and find middle character
        for(int i=0; i<26; i++){
             
            // Add half of the occurances to the left
            left += string(freq[i]/2, char(i + 'a'));

            // If frequency is odd, this character goes in the middle
            if(freq[i] % 2 == 1){
                middle = char(i + 'a');
            }
        }

        // Right half is reserved of left half
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right; 
    }
};