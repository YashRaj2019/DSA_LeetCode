class Solution {
public:
    bool isPowerOfTwo(int n) {

        // method 1: 
        // if(n<=0){
        //     return 0;
        // }

        // while(n%2==0){
        //     n = n/2;
        // }
        // return n == 1;

        // method 2: using bit manupulation
        if (n > 0 && (n & (n - 1)) == 0){
            return true;
        }      
        else{
            return false;
        }
    }
};