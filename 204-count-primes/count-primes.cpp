// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<bool> isPrime(n+1, true);
//         int count = 0;

//         for(int i=2; i<n; i++){
//             if(isPrime[i]){
//                 count++;
//             }

//             for(int j=i*2; j<n; j=j+i){ // to discard multiples of any number
//                 isPrime[j] = false;
//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i < n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++) {
            if(isPrime[i]) count++;
        }

        return count;
    }
};


