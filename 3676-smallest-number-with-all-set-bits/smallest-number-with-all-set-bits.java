class Solution {
    public int smallestNumber(int n) {

        // int ans = 0;                // method 1
        // for(int i=0; i<31; i++){
        //     ans = (ans << 1) | 1;

        //     if(ans >= n){
        //         return ans;
        //     }
        // }

        // return ans;

        // method 2 :
        int num = 1;

        while(num < n){
            num = num * 2 + 1;
        }
        return num;
    }
}