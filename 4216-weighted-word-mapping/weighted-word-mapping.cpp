class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i=0;i<words.size();i++){
            int sum = 0;

            for(int j=0;j<words[i].size();j++){
                char ch = words[i][j];
                sum = sum+weights[ch - 'a'];
            }

            int rem = sum %26;

            char mapped = 'z' - rem;
            ans = ans + mapped;
        }

        return ans;
    }
};