class Solution {
public:
    int maxProduct(int n) {
        
        
        vector<int>arr;
        while(n!=0){
            int digit = n%10;
            arr.push_back(digit);
            n /=10;
        }

        sort(arr.begin(), arr.end());
        int a = arr.size();

        return arr[a-2] * arr[a-1];

    }
};