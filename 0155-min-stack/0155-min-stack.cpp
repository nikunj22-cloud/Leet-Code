class MinStack {
public:
  stack<long long int>st;
  long long int minval;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minval = val;
        }
        else{
            if( val < minval){
                st.push((long long)2*val - minval);
                 minval = val;
            }
            else{
                st.push(val);
            }
        }
        
    }
    
    void pop() {
        if(st.top() <  minval){
            //hm stack m minval se bhi choti val push krrhe h
            //so hmko phle wali min val ko wps lane k liye 
             minval = 2*minval-st.top();
        }
        st.pop();
        }
    
    
    int top() {
        if( st.top() < minval){
            return minval;
            //because hm stack m minval se b choti value push krrhe h or top  krte time original 
            //value chahie so direct minval return krdi joh ki top k corasponding minval hogi
        }
        return st.top();
    }
    
    int getMin() {
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */