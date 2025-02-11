class MyStack {
 private:
        stack<int>st; //define stack
public:
        MyStack(){ //constructor

        }
        
    
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int topElement = st.top();
      
        st.pop();

        return topElement;
        
    }
    
    int top() {
        if( st.empty()) return -1;
        
        return st.top();
    }
    
    bool empty() {
        return st.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */