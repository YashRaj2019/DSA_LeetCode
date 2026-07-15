class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;

        if(s.size() != t.size()){
            return false;
        }

        vector<int>ans(26,0);
        for(int i=0; i<s.size(); i++){
            ans[s[i] - 'a']++;
            ans[t[i] - 'a']--;
        }

        for(auto it: ans){
            if(it != 0){
                return false;
            }
        }
        return true;
    }
};