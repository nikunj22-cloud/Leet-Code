class Solution {
public:
    bool isValid(string s) {
        stack<char>st;  //ham ulte elemenet insert krnege
         for( char &ch : s){
            if( ch == '('){
                st.push(')');
            }
            else if(ch == '{'){
                st.push('}');
            }
            else if( ch == '['){
                st.push(']');
            }
            else if(st.empty() || st.top() != ch){ //yeh conditon tb bnegi jb stack ya toh empty h ya fir stack ka top element ch k barbar nhi h mtlb stack main koi closing bracket ni h
                return false;
            }
            else{
                st.pop();
            } //agr match ho gya element toh pop krdo 

         }
         return st.empty();
    }
};