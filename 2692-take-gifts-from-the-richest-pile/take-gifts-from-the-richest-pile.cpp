class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>p;// max heap
        for(int i=0; i<gifts.size();i++){
            p.push(gifts[i]);
        }

        // perform k operations
        while(k--){
            int top = p.top();
            p.pop();

            int newVal = floor(sqrt(top));
            p.push(newVal);
        }

        // sum remaining elements
        long long sum = 0;
        while(!p.empty()){
            sum += p.top();
            p.pop();
        }

        return sum;
    }
};