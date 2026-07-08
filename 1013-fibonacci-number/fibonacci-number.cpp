class Solution {
public:
    int fib(int n) {
        // method 2 : using recursion
        if(n<=1){
            return n;
        }

        return fib(n-1) + fib(n-2);
    }
};