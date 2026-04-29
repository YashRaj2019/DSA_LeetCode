// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         while(s.length() > 0 && s.find(part) < s.length()){
//             s.erase(s.find(part), part.length());
//         }
//         return s;
//     }
// };

// method 2: using stack

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int m = part.length();

        for(char ch : s){
            result.push_back(ch);

            // check if last m characters match "part"
            if(result.size() >= m &&
               result.substr(result.size() - m) == part){
                result.erase(result.size() - m);
            }
        }

        return result;
    }
};