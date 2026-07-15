class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // return n; // method 1

        int oddSum = n * n;
        int evenSum = n * (n + 1);

        while(oddSum > 0 && evenSum > 0){
            if(oddSum > evenSum){
                oddSum = oddSum % evenSum;
            }
            else{
                evenSum = evenSum % oddSum;
            }

        }

        if(oddSum == 0){
            return evenSum;
        }
        return oddSum;
    }
};