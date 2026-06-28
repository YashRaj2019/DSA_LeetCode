class Solution {
public:
    int firstUniqChar(string s) {
        
        // method 1
        unordered_map<char, int>mp;

        // count the frequency
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};