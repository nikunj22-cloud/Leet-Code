class MyQueue {
    private:
        stack<int>st1;
        stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){ //move all element in to stack2
                st2.push(st1.top());
                st1.pop();
            }
        }
            if(st2.empty()){
                cout<<"queue is empty";
                return -1;
            }
            int topElement = st2.top();
            st2.pop();
            return topElement;
        
    }
    //see the front elment of the queue
    int peek() {
        if(st2.empty()){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        } 
    }  
        if(st2.empty()){
            cout<<"queue is empty";
            return -1;
        }
        return st2.top();
    }
    
    bool empty() {
       return  st1.empty() && st2.empty();
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