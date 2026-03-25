class Solution {
public:
    bool isPossible(vector<int>& target) {

        int n = target.size();
        if(n==1){
            return target[0] == 1;
        }

        priority_queue<long long >pq;
        long long sum = 0;

        for(int x:target){
            pq.push(x);
            sum += x;
        }

        while(true){
            long long maxi = pq.top();
            pq.pop();

            long long rest = sum - maxi;

            // if largest is 1, all must be 1
            if(maxi == 1 || rest == 1){
                return true;
            }

            // invalid cases
            if(rest == 0 || maxi <= rest){
                return false;
            }

            long long prev = maxi % rest;

            if(prev == 0){
                return false;
            }

            pq.push(prev);
            sum = rest + prev;

        }

    }
};