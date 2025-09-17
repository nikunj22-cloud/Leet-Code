class MyQueue {
public:
  stack<int>input ;
  stack<int>output;
    MyQueue() {
        
    }
    int peekEl = -1; 
    //peekEl isliye rakha gaya hai:

// jab tak output stack empty hai, queue ka front direct nahi milta.

// uss case me peekEl store karke rakha gaya hai taaki O(1) me front element mil jaaye, bina stacks transfer kiye.
    void push(int x) {
         if(input.empty()){
            peekEl = x;
         }      
         input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
         int val = output.top();
        output.pop();
        return val;

    }
    
    int peek() {
        if(output.empty()){
            return peekEl;
        }
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty()){
            return true;
        }
        return false;
        
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