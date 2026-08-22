class Solution {
public:
    bool checkDivisibility(int n) {
       
       int org = n;
       int sum = 0;
       int mul = 1;

       while(n){
            int digit = n%10;
            sum += digit;
            mul *= digit;

            n /=10;
        }

        int ans = sum + mul;

       if(org % ans == 0){
            return true;
        }

        return false;
    }
};