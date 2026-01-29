class Solution {
public:
    void reverseString(vector<char>& s) {

    //   int start = 0, end=s.size()-1;
    //   while(start<end){
    //     swap(s[start], s[end]);
    //     start++, end--;

    //   }

    //    return ; 
        

        // Method 2

        stack<char>st;

        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }

        int i = 0;
        while(!st.empty()){
            s[i]=st.top();
            i++;
            st.pop();
        }
        return;
    }
};