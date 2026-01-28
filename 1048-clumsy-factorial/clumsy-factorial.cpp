class Solution {
public:
    int clumsy(int n) {
       stack<int>s;
       int num, i = 0;
       s.push(n);
       n--;

       while(n){
        // multiply, when i = 0

        if(i==0){
            num = s.top();
            s.pop();
            s.push(num*n);
        }

        // divide, when i = 1

        else if(i==1){
            num = s.top();
            s.pop();
            s.push(num/n);
        }

        else{
            s.push(n);
        }
            i = (i+1)%4;
            n--;
       }

       stack<int>ans;
       while(s.size()){
            ans.push(s.top());
            s.pop();
       }

       int sum = ans.top();
       ans.pop();
       bool flag = 0;

       while(ans.size()){
          if(flag==0){
            sum += ans.top();
          }

          else{
            sum -= ans.top();
          }
            ans.pop();
            flag =! flag;
       }

       return sum;
    }
};