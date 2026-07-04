class Solution {
public:
    string removeStars(string s) {
        
        // method 1 : using loop

        // string str = "";
        // for(char ch : s){
        //     if(ch == '*'){
        //         str.pop_back();
        //     }
        //     else{
        //         str.push_back(ch);
        //     }
        // }

        // return str;

        // method 2: using stack
        stack<char>st;
        for(char ch : s){
            if(ch == '*'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};