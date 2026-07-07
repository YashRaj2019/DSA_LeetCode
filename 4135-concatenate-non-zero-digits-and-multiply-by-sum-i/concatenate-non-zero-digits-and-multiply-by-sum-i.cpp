class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num =0;
        long long sum =0;
        string str = to_string(n);
        for(int i=0; i<str.size(); i++){
            if(str[i] != '0'){
                int digit = str[i] - '0';
                num = num * 10 + digit;

                sum += digit;
            }
            
        }
        return num*sum;
    }
};