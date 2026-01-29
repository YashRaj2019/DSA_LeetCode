class Solution {
public:

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int start = 0, end = s.size() - 1;

        while(start < end){
            while(start < end && !isVowel(s[start])){
                start++;
            }
            while(start < end && !isVowel(s[end])){
                end--;
            }

            swap(s[start], s[end]);
            start++, end--;
        }
        return s;
    }
};