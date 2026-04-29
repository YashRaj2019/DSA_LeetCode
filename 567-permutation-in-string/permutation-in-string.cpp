// class Solution {
// public:

//     bool isFreqSame(int freq1[], int freq2[]){
//         for(int i=0; i<26; i++){
//             if(freq1[i] != freq2[i]){
//                 return false;
//             }
//         }

//         return true;
//     }

//     bool checkInclusion(string s1, string s2) {
//         int freq[26] = {0};

//         for(int i=0; i<s1.length(); i++){
//             freq[s1[i] - 'a']++;
//         }

//         int windSize = s1.length();

//         for(int i=0; i<s2.length(); i++){
//             int windIdx = 0, idx = i;
//             int windFreq[26] = {0};

//             while(windIdx < windSize && idx < s2.length()){
//                 windFreq[s2[idx] - 'a']++;
//                 windIdx++;
//                 idx++;
//             }

//             if(isFreqSame(freq, windFreq)){ // found
//                 return true;
//             }
//         }

//         return false;
//     }
// };


// method 2 using unordered map

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if(k > s2.size()) return false;

        unordered_map<char, int> m1, m2;

        // frequency of s1
        for(char c : s1) m1[c]++;

        // first window
        for(int i = 0; i < k; i++) m2[s2[i]]++;

        if(m1 == m2) return true;

        // sliding window
        for(int i = k; i < s2.size(); i++){
            m2[s2[i]]++;              // add new char
            m2[s2[i-k]]--;            // remove old char

            if(m2[s2[i-k]] == 0) m2.erase(s2[i-k]);

            if(m1 == m2) return true;
        }

        return false;
    }
};