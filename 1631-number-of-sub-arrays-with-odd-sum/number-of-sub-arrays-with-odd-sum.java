class Solution {
    public int numOfSubarrays(int[] arr) {


        int mod = 1000000007;
        int even = 1, odd = 0, sum = 0, ans = 0;

        for(int i=0; i<arr.length; i++){
            sum += arr[i];

            if(sum % 2 == 0){
                ans = (ans + odd) % mod;
                even++;
            }
            else{
                ans = (ans + even) % mod;
                odd++;
            }
        }
        return ans;

    //     // brute force : tle
    //     int count = 0;
    //     int mod = 100000007;

    //     for(int i=0; i<arr.length; i++){
    //         int sum = 0;
    //         for(int j=i; j<arr.length; j++){
    //             sum += arr[j];

    //             if(sum % 2 != 0){
    //                 count = (count + 1) % mod;
    //             }
    //         }
    //     }
    //     return count;

    
    }
}