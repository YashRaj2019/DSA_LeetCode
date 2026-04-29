class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i = 0; i < n; i++){
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch){
                count++;
                i++;
            }

            // write character
            chars[idx++] = ch;

            // write count only if > 1
            if(count > 1){
                string str = to_string(count);
                for(char digit : str){
                    chars[idx++] = digit;
                }
            }

            i--; // adjust because for loop will increment
        }

        chars.resize(idx);
        return idx;
    }
};