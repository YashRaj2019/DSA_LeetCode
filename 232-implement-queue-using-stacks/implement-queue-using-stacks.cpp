// class MyQueue {
// public:
//     stack<int>st1; // for push operation
//     stack<int>st2; // for pop operation
//     MyQueue() {
        
//     }

//     bool empty() {
//         return st1.empty() && st2.empty();
//     }
    
//     void push(int x) {
//         st1.push(x);
//     }
    
//     int pop() {
//         // empty
//         if(empty()){
//             return 0;
//         }

//         else if(!st2.empty()){
//             int element = st2.top();
//             st2.pop();
//             return element;
//         }

//         else{
//             while(!st1.empty()){
//                 st2.push(st1.top());
//                 st1.pop();
//             }

//             int element = st2.top();
//             st2.pop();
//             return element;
//         }
//     }
    
//     int peek() {
//         if(empty()){
//             return 0;
//         }

//         else if(!st2.empty()){
//             return st2.top();
//         }

//         else{
//              while(!st1.empty()){
//                 st2.push(st1.top());
//                 st1.pop();
//             }

//         }

//         return st2.top();
//     }  
    
// };

// method 2:
class MyQueue {
public:
    stack<int>s1; // for push operation
    stack<int>s2; // for pop operation
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }

        bool empty() {
            return s1.empty();
        }
 
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */