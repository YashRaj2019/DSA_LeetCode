class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i=1;i*i<=num;i++){
            if(i*i == num){
                return 1;
            }

        }
        return 0;
    }
};