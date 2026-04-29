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

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int k = s1.size();
//         if(k > s2.size()) return false;

//         unordered_map<char, int> m1, m2;

//         // frequency of s1
//         for(char c : s1) m1[c]++;

//         // first window
//         for(int i = 0; i < k; i++) m2[s2[i]]++;

//         if(m1 == m2) return true;

//         // sliding window
//         for(int i = k; i < s2.size(); i++){
//             m2[s2[i]]++;              // add new char
//             m2[s2[i-k]]--;            // remove old char

//             if(m2[s2[i-k]] == 0) m2.erase(s2[i-k]);

//             if(m1 == m2) return true;
//         }

//         return false;
//     }
// };

// method 3 : using array

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int k = s1.size();
//         if(k > s2.size()) return false;

//         vector<int> freq1(26, 0), freq2(26, 0);

//         // build freq for s1 and first window
//         for(int i = 0; i < k; i++){
//             freq1[s1[i] - 'a']++;
//             freq2[s2[i] - 'a']++;
//         }

//         if(freq1 == freq2) return true;

//         // sliding window
//         for(int i = k; i < s2.size(); i++){
//             freq2[s2[i] - 'a']++;          // add new char
//             freq2[s2[i-k] - 'a']--;        // remove old char

//             if(freq1 == freq2) return true;
//         }

//         return false;
//     }
// };

//  method 4: most optimised and efficient

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if(k > s2.size()) return false;

        vector<int> freq(26, 0);

        for(char c : s1) freq[c - 'a']++;

        int left = 0, right = 0, count = k;

        while(right < s2.size()){
            if(freq[s2[right] - 'a']-- > 0){
                count--;
            }
            right++;

            if(count == 0) return true;

            if(right - left == k){
                if(freq[s2[left] - 'a']++ >= 0){
                    count++;
                }
                left++;
            }
        }

        return false;
    }
};
