class Solution {
public:
    int reverseBits(int n) {

        // method 1

        // unsigned int result = 0;
        // unsigned int num = n;

        // for(int i=0;i<32;i++){
        //     result = (result << 1) | (num & 1);
        //     num  = num >> 1;
            
        // }

        // return result;

        // method 2

        unsigned int res = 0;
        
        for(int i = 0; i < 32; i++) {
            res = res * 2 + (n & 1);
            n = n >> 1;
        }
        
        return res;


    }
};