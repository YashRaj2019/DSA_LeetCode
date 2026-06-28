class Solution {
public:
    int firstUniqChar(string s) {
        
        // method 1
        // unordered_map<char, int>mp;

        // // count the frequency
        // for(int i=0; i<s.size(); i++){
        //     mp[s[i]]++;
        // }

        // for(int i=0; i<s.size(); i++){
        //     if(mp[s[i]] == 1){
        //         return i;
        //     }
        // }

        // return -1;

        // for(int i=0; i<s.size(); i++){  // O(n^2)
        //     if(s.find(s[i]) == s.rfind(s[i])){
        //         return i;
        //     }
        // }

        // return -1;

        unordered_map<char, int>m;
        queue<int>q;

        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }

            m[s[i]]++;

            while(q.size() > 0 && m[s[q.front()]] > 1){
                q.pop();
            } 
        }

        return q.empty() ? -1 : q.front();
    }
};